#include "utils.h"
#include "caesar.h"
#include "vigenere.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void on_encrypt_button_clicked(GtkButton *button, gpointer user_data) {
    AppWidgets *widgets = (AppWidgets *)user_data;
    if (!widgets->file_path) return;

    gchar *content = read_file(widgets->file_path);
    if (!content) return;

    const gchar *key = gtk_entry_get_text(GTK_ENTRY(widgets->key_entry));
    int cipher_type = gtk_combo_box_get_active(GTK_COMBO_BOX(widgets->combo_box));

    if (cipher_type == 0) { // Caesar Cipher
        int caesar_key = atoi(key);
        caesar_encrypt(content, caesar_key);
    } else if (cipher_type == 1) { // Vigenere Cipher
        vigenere_encrypt(content, key);
    }

    write_file(widgets->file_path, content);
    g_free(content);
}

void on_decrypt_button_clicked(GtkButton *button, gpointer user_data) {
    AppWidgets *widgets = (AppWidgets *)user_data;
    if (!widgets->file_path) return;

    gchar *content = read_file(widgets->file_path);
    if (!content) return;

    const gchar *key = gtk_entry_get_text(GTK_ENTRY(widgets->key_entry));
    int cipher_type = gtk_combo_box_get_active(GTK_COMBO_BOX(widgets->combo_box));

    if (cipher_type == 0) { // Caesar Cipher
        int caesar_key = atoi(key);
        caesar_decrypt(content, caesar_key);
    } else if (cipher_type == 1) { // Vigenere Cipher
        vigenere_decrypt(content, key);
    }

    write_file(widgets->file_path, content);
    g_free(content);
}

void on_file_set(GtkFileChooserButton *button, gpointer user_data) {
    AppWidgets *widgets = (AppWidgets *)user_data;
    widgets->file_path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(button));
}

gchar* read_file(const gchar *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) return NULL;

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    gchar *content = g_malloc(length + 1);
    fread(content, 1, length, file);
    content[length] = '\0';

    fclose(file);
    return content;
}

void write_file(const gchar *file_path, const gchar *content) {
    FILE *file = fopen(file_path, "w");
    if (!file) return;

    fwrite(content, 1, strlen(content), file);
    fclose(file);
}