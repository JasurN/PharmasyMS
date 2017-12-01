
#include <gtk/gtk.h>
GtkBuilder *builder;
GtkWidget *window, *window1;
int main(int argc, char **argv)
{


    gtk_init(&argc, &argv);
    builder=gtk_builder_new();
    if(gtk_builder_add_from_file(builder, "login_frame.glade", NULL) == 0)
    {
        printf(".glade file is not exist");
        return (0);
    }

    window=GTK_WIDGET( gtk_builder_get_object(builder, "logwindow"));

    gtk_builder_connect_signals(builder, NULL);
    gtk_widget_show_all(window);
    gtk_main();
    return (0);
}
void on_enter_but_clicked(){
    const gchar* login;
    const gchar* password;

    GtkEntry* log = (GtkEntry*) gtk_builder_get_object(builder, "login_field");
    GtkEntry* pass=(GtkEntry*) gtk_builder_get_object(builder, "password_field");
    login=gtk_entry_get_text(log);
    password=gtk_entry_get_text(pass);
    window1=GTK_WIDGET( gtk_builder_get_object(builder, "window1"));
    gtk_widget_show_all(window1);
    g_print(login);
    g_print(password);

}