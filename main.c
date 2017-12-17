#include <gtk/gtk.h>
#include <string.h>
#define username "admin"

GtkBuilder *builder;
GtkWidget *window, *window1;
GtkCellRenderer *renderer;
GtkTreeViewColumn *col;

enum {
    LIST_ID,
    LIST_BRAND,
    LIST_MODEL,
    LIST_PRICE,
    N_COLUMNS
};

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
   const char* login;
   const char* password;

   GtkEntry* log = (GtkEntry*) gtk_builder_get_object(builder, "login_field");
   GtkEntry* pass=(GtkEntry*) gtk_builder_get_object(builder, "password_field");
   login=gtk_entry_get_text(log);
   password=gtk_entry_get_text(pass);
    char *name="OxyMed";
   if (strcmp(login, username)==0 && strcmp(password, username)==0){

      window1=GTK_WIDGET( gtk_builder_get_object(builder, "window1"));
       GtkLabel* storename=(GtkLabel*) gtk_builder_get_object(builder, "drugstore");
       gtk_label_set_text(GTK_LABEL(storename), name);
       GtkTreeView* list=(GtkTreeView*) gtk_builder_get_object(builder,"table1");
       renderer=gtk_cell_renderer_text_new();
       col=gtk_tree_view_column_new_with_attributes("ID", renderer,"text",LIST_ID,NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(list), col);



      gtk_widget_show_all(window1);
      gtk_widget_destroy(window);
      g_print(login);
      g_print(password);
   } else{
       GtkLabel* warn=(GtkLabel*) gtk_builder_get_object(builder, "warning");
       const gchar *text = "Login or Password wrong";
       gtk_label_set_text(GTK_LABEL(warn), text);
      g_print("Wrong");

   }
}