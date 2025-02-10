#include <gtk/gtk.h>
#include "utils.h"

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    AppWidgets *widgets = g_slice_new(AppWidgets);

    widgets->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(widgets->window), "Encryption Tool");
    gtk_window_set_default_size(GTK_WINDOW(widgets->window), 400, 300);

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(widgets->window), vbox);

    widgets->file_chooser = gtk_file_chooser_button_new("Choose a file", GTK_FILE_CHOOSER_ACTION_OPEN);
    gtk_box_pack_start(GTK_BOX(vbox), widgets->file_chooser, FALSE, FALSE, 0);
    g_signal_connect(widgets->file_chooser, "file-set", G_CALLBACK(on_file_set), widgets);

    widgets->combo_box = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(widgets->combo_box), "Caesar Cipher");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(widgets->combo_box), "Vigenere Cipher");
    gtk_box_pack_start(GTK_BOX(vbox), widgets->combo_box, FALSE, FALSE, 0);

    widgets->key_entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(widgets->key_entry), "Enter key");
    gtk_box_pack_start(GTK_BOX(vbox), widgets->key_entry, FALSE, FALSE, 0);

    GtkWidget *button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_box_pack_start(GTK_BOX(vbox), button_box, FALSE, FALSE, 0);

    GtkWidget *encrypt_button = gtk_button_new_with_label("Encrypt");
    g_signal_connect(encrypt_button, "clicked", G_CALLBACK(on_encrypt_button_clicked), widgets);
    gtk_container_add(GTK_CONTAINER(button_box), encrypt_button);

    GtkWidget *decrypt_button = gtk_button_new_with_label("Decrypt");
    g_signal_connect(decrypt_button, "clicked", G_CALLBACK(on_decrypt_button_clicked), widgets);
    gtk_container_add(GTK_CONTAINER(button_box), decrypt_button);

    widgets->text_view = gtk_text_view_new();
    gtk_box_pack_start(GTK_BOX(vbox), widgets->text_view, TRUE, TRUE, 0);

    g_signal_connect(widgets->window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(widgets->window);
    gtk_main();

    g_slice_free(AppWidgets, widgets);
    return 0;
}