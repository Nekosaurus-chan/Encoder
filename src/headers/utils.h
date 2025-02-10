#include <gtk/gtk.h>

typedef struct {
    GtkWidget *window;
    GtkWidget *file_chooser;
    GtkWidget *combo_box;
    GtkWidget *key_entry;
    GtkWidget *text_view;
    gchar *file_path;
} AppWidgets;

void on_encrypt_button_clicked(GtkButton *button, gpointer user_data);
void on_decrypt_button_clicked(GtkButton *button, gpointer user_data);
void on_file_set(GtkFileChooserButton *button, gpointer user_data);
gchar* read_file(const gchar *file_path);
void write_file(const gchar *file_path, const gchar *content);