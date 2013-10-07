
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif


#include <glib.h>
#include <gtk/gtk.h>
#include <unistd.h>
#include <sys/stat.h>
#include <gdk/gdkkeysyms.h>
//
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
//
#include "griffon_defs.h"
#include "griffon_options.h"
#include "griffon_gtk_utils.h"
#include "griffon_config.h"



static void on_kwas_notebook_switch_page (GtkNotebook *notebook,
                                          GtkWidget *page,
                                          guint page_num,
                                          gpointer user_data)
{
  confile.last_prefs_tab = page_num;      
}


static void cb_on_bt_apply (GObject *object, GtkWidget *w) 
{
   GList *l = NULL;

   l = add_to_glist_combined_str (l, "fmt_color_function", gtk_entry_get_text (GTK_ENTRY (ent_fmt_color_function)));

   l = add_to_glist_combined_str (l, "def_save_dir", gtk_entry_get_text (GTK_ENTRY (ent_def_save_dir)));
   l = add_to_glist_combined_str (l, "def_open_dir", gtk_entry_get_text (GTK_ENTRY (ent_def_open_dir)));

   l = add_to_glist_combined_str (l, "mplayer", gtk_entry_get_text (GTK_ENTRY (ent_cm_mplayer)));
   l = add_to_glist_combined_str (l, "mozilla", gtk_entry_get_text (GTK_ENTRY (ent_cm_mozilla)));
   l = add_to_glist_combined_str (l, "konqueror", gtk_entry_get_text (GTK_ENTRY (ent_cm_konqueror)));
   l = add_to_glist_combined_str (l, "firefox", gtk_entry_get_text (GTK_ENTRY (ent_cm_firefox)));
   l = add_to_glist_combined_str (l, "opera", gtk_entry_get_text (GTK_ENTRY (ent_cm_opera)));
   l = add_to_glist_combined_str (l, "links", gtk_entry_get_text (GTK_ENTRY (ent_cm_links)));
   l = add_to_glist_combined_str (l, "elinks", gtk_entry_get_text (GTK_ENTRY (ent_cm_elinks)));
   l = add_to_glist_combined_str (l, "dillo", gtk_entry_get_text (GTK_ENTRY (ent_cm_dillo)));
   l = add_to_glist_combined_str (l, "galeon", gtk_entry_get_text (GTK_ENTRY (ent_cm_galeon)));
   l = add_to_glist_combined_str (l, "epiphany", gtk_entry_get_text (GTK_ENTRY (ent_cm_epiphany)));

   l = add_to_glist_combined_str (l, "other", gtk_entry_get_text (GTK_ENTRY (ent_cm_other)));
   l = add_to_glist_combined_str (l, "lynx", gtk_entry_get_text (GTK_ENTRY (ent_cm_lynx)));
   l = add_to_glist_combined_str (l, "def_doc_browser", gtk_entry_get_text (GTK_ENTRY (ent_cm_manual_browser)));

   l = add_to_glist_combined_str (l, "date_time", gtk_entry_get_text (GTK_ENTRY (ent_date_time)));

   l = add_to_glist_combined_str (l, "tag_color_lm_error_fg", gtk_entry_get_text (GTK_ENTRY (ent_tag_color_lm_error_fg)));
   l = add_to_glist_combined_str (l, "tag_color_lm_error_bg", gtk_entry_get_text (GTK_ENTRY (ent_tag_color_lm_error_bg)));

   //l = add_to_glist_combined_str (l, "tag_comment", gtk_entry_get_text (GTK_ENTRY (ent_tag_comment)));
   //l = add_to_glist_combined_str (l, "tag_identifier", gtk_entry_get_text (GTK_ENTRY (ent_tag_identifier)));
   //l = add_to_glist_combined_str (l, "tag_digit", gtk_entry_get_text (GTK_ENTRY (ent_tag_digit)));
   //l = add_to_glist_combined_str (l, "tag_string", gtk_entry_get_text (GTK_ENTRY (ent_tag_string)));
   //l = add_to_glist_combined_str (l, "tag_html_tag", gtk_entry_get_text (GTK_ENTRY (ent_tag_html_tag)));

   //l = add_to_glist_combined_str (l, "tag_preprocessor", gtk_entry_get_text (GTK_ENTRY (ent_tag_preprocessor)));
   //l = add_to_glist_combined_str (l, "tag_type", gtk_entry_get_text (GTK_ENTRY (ent_tag_type)));
   l = add_to_glist_combined_str (l, "tag_spellcheck", gtk_entry_get_text (GTK_ENTRY (ent_tag_spellcheck)));

   l = add_to_glist_combined_str (l, "text_foreground", gtk_entry_get_text (GTK_ENTRY (ent_text_foreground)));
   l = add_to_glist_combined_str (l, "text_background", gtk_entry_get_text (GTK_ENTRY (ent_text_background)));
 
   l = add_to_glist_combined_str (l, "text_sel_foreground", gtk_entry_get_text (GTK_ENTRY (ent_text_sel_foreground)));
   l = add_to_glist_combined_str (l, "text_sel_background", gtk_entry_get_text (GTK_ENTRY (ent_text_sel_background)));

   l = add_to_glist_combined_str (l, "def_filesave_charset", gtk_entry_get_text (GTK_ENTRY (ent_def_filesave_charset)));
   l = add_to_glist_combined_str (l, "default_charset", gtk_entry_get_text (GTK_ENTRY (ent_default_charset)));
   l = add_to_glist_combined_str (l, "rtf_enc", gtk_entry_get_text (GTK_ENTRY (ent_rtf_enc)));
   l = add_to_glist_combined_str (l, "tag_comment_font", gtk_entry_get_text (GTK_ENTRY (ent_tag_comment_font)));

   l = add_to_glist_combined_str (l, "tag_identifier_font", gtk_entry_get_text (GTK_ENTRY (ent_tag_identifier_font)));
   l = add_to_glist_combined_str (l, "tag_digit_font", gtk_entry_get_text (GTK_ENTRY (ent_tag_digit_font)));

   l = add_to_glist_combined_str (l, "tag_string_font", gtk_entry_get_text (GTK_ENTRY (ent_tag_string_font)));
   l = add_to_glist_combined_str (l, "tag_html_tag_font", gtk_entry_get_text (GTK_ENTRY (ent_tag_html_tag_font)));

   l = add_to_glist_combined_str (l, "tag_preprocessor_font", gtk_entry_get_text (GTK_ENTRY (ent_tag_preprocessor_font)));
   l = add_to_glist_combined_str (l, "tag_type_font", gtk_entry_get_text (GTK_ENTRY (ent_tag_type_font)));

   l = add_to_glist_combined_str (l, "editor_font", gtk_entry_get_text (GTK_ENTRY (ent_editor_font)));
   l = add_to_glist_combined_str (l, "ext_pic_editor", gtk_entry_get_text (GTK_ENTRY (ent_ext_pic_editor)));
   l = add_to_glist_combined_str (l, "ext_pic_viewer", gtk_entry_get_text (GTK_ENTRY (ent_ext_pic_viewer)));

   l = add_to_glist_combined_bool (l, "prompt_on_not_saved", gtk_toggle_button_get_active (&cb_prompt_on_not_saved->toggle_button));
   l = add_to_glist_combined_bool (l, "prompt_on_file_exists", gtk_toggle_button_get_active (&cb_prompt_on_file_exists->toggle_button));
   l = add_to_glist_combined_bool (l, "warn_about_aliens", gtk_toggle_button_get_active (&cb_warn_about_aliens->toggle_button));

   l = add_to_glist_combined_bool (l, "do_det_scripts_by_content", gtk_toggle_button_get_active (&cb_do_det_scripts_by_content->toggle_button));
   l = add_to_glist_combined_bool (l, "do_show_main_toolbar", gtk_toggle_button_get_active (&cb_do_show_main_toolbar->toggle_button));



   l = add_to_glist_combined_bool (l, "xhtml_mode", gtk_toggle_button_get_active (&cb_xhtml_mode->toggle_button));
   l = add_to_glist_combined_bool (l, "use_snippets", gtk_toggle_button_get_active (&cb_use_snippets->toggle_button));
   l = add_to_glist_combined_bool (l, "use_ext_image_viewer", gtk_toggle_button_get_active (&cb_use_ext_image_viewer->toggle_button));

   l = add_to_glist_combined_bool (l, "do_hl_on_fileopen", gtk_toggle_button_get_active (&cb_do_hl_on_fileopen->toggle_button));
   l = add_to_glist_combined_bool (l, "do_backup", gtk_toggle_button_get_active (&cb_do_backup->toggle_button));

   l = add_to_glist_combined_bool (l, "start_with_blank_file", gtk_toggle_button_get_active (&cb_start_with_blank_file->toggle_button));
   l = add_to_glist_combined_bool (l, "start_with_recent_file", gtk_toggle_button_get_active (&cb_start_with_recent_file->toggle_button));

   l = add_to_glist_combined_bool (l, "use_def_doc_browser", gtk_toggle_button_get_active (&cb_use_def_doc_browser->toggle_button));

   l = add_to_glist_combined_bool (l, "show_line_nums", gtk_toggle_button_get_active (&cb_show_line_nums->toggle_button));
   l = add_to_glist_combined_bool (l, "word_wrap", gtk_toggle_button_get_active (&cb_word_wrap->toggle_button));
   //l = add_to_glist_combined_bool (l, "use_autocomp", gtk_toggle_button_get_active (&cb_use_autocomp->toggle_button));
   l = add_to_glist_combined_bool (l, "use_def_save_dir", gtk_toggle_button_get_active (&cb_use_def_save_dir->toggle_button));
   l = add_to_glist_combined_bool (l, "use_def_open_dir", gtk_toggle_button_get_active (&cb_use_def_open_dir->toggle_button));
   l = add_to_glist_combined_bool (l, "use_auto_indent", gtk_toggle_button_get_active (&cb_use_auto_indent->toggle_button));
	l = add_to_glist_combined_bool (l, "use_infotext", gtk_toggle_button_get_active (&cb_use_infotext->toggle_button));
	l = add_to_glist_combined_bool (l, "use_spellcheck", gtk_toggle_button_get_active (&cb_use_spellcheck->toggle_button));
		l = add_to_glist_combined_bool (l, "use_textcompbloc", gtk_toggle_button_get_active (&cb_use_textcompbloc->toggle_button));

   l = add_to_glist_combined_bool (l, "ins_spaces_on_tab_press", gtk_toggle_button_get_active (&cb_ins_spaces_on_tab_press->toggle_button));
   l = add_to_glist_combined_bool (l, "scan_for_links_on_doc_open", gtk_toggle_button_get_active (&cb_scan_for_links_on_doc_open->toggle_button));
   l = add_to_glist_combined_bool (l, "main_wnd_show_full_path", gtk_toggle_button_get_active (&cb_main_wnd_show_full_path->toggle_button));

   l = add_to_glist_combined_bool (l, "enc_det_cp1251", gtk_toggle_button_get_active (&cb_enc_det_cp1251->toggle_button));
   l = add_to_glist_combined_bool (l, "enc_det_koi8r", gtk_toggle_button_get_active (&cb_enc_det_koi8r->toggle_button));

   l = add_to_glist_combined_bool (l, "enc_det_koi8u", gtk_toggle_button_get_active (&cb_enc_det_koi8u->toggle_button));
   l = add_to_glist_combined_bool (l, "enc_det_866", gtk_toggle_button_get_active (&cb_enc_det_866->toggle_button));

   l = add_to_glist_combined_bool (l, "enc_det_finnish", gtk_toggle_button_get_active (&cb_enc_det_finnish->toggle_button));
   l = add_to_glist_combined_bool (l, "enc_det_german", gtk_toggle_button_get_active (&cb_enc_det_german->toggle_button));

   l = add_to_glist_combined_bool (l, "enc_det_serbian", gtk_toggle_button_get_active (&cb_enc_det_serbian->toggle_button));
   l = add_to_glist_combined_bool (l, "enc_det_latvian", gtk_toggle_button_get_active (&cb_enc_det_latvian->toggle_button));

   l = add_to_glist_combined_bool (l, "enc_det_polish", gtk_toggle_button_get_active (&cb_enc_det_polish->toggle_button));
   l = add_to_glist_combined_bool (l, "enc_det_portuguese", gtk_toggle_button_get_active (&cb_enc_det_portuguese->toggle_button));

   l = add_to_glist_combined_bool (l, "enc_det_slovak", gtk_toggle_button_get_active (&cb_enc_det_slovak->toggle_button));
   l = add_to_glist_combined_bool (l, "enc_det_slovenian", gtk_toggle_button_get_active (&cb_enc_det_slovenian->toggle_button));

   l = add_to_glist_combined_bool (l, "enc_det_spanish", gtk_toggle_button_get_active (&cb_enc_det_spanish->toggle_button));
   l = add_to_glist_combined_bool (l, "enc_det_turkish", gtk_toggle_button_get_active (&cb_enc_det_turkish->toggle_button));

   l = add_to_glist_combined_bool (l, "show_hidden_files", gtk_toggle_button_get_active (&cb_show_hidden_files->toggle_button));
   l = add_to_glist_combined_bool (l, "do_autorep", gtk_toggle_button_get_active (&cb_do_autorep->toggle_button));

//   l = add_to_glist_combined_int (l, "logmemo_lines_max", gtk_spin_button_get_value_as_int (sb_logmemo_lines_max));  
   l = add_to_glist_combined_int (l, "famous_history_max", gtk_spin_button_get_value_as_int (sb_famous_history_max));  
   l = add_to_glist_combined_int (l, "max_recent_items", gtk_spin_button_get_value_as_int (sb_max_recent_items));  
   //l = add_to_glist_combined_int (l, "autocomp_wordlen_min", gtk_spin_button_get_value_as_int (sb_autocomp_wordlen_min));  
   //l = add_to_glist_combined_int (l, "autocomp_list_items_max", gtk_spin_button_get_value_as_int (sb_autocomp_list_items_max));  


   l = add_to_glist_combined_int (l, "thumb_width", gtk_spin_button_get_value_as_int (sb_thumb_width));  
   l = add_to_glist_combined_int (l, "thumb_height", gtk_spin_button_get_value_as_int (sb_thumb_height));  


  // l = add_to_glist_combined_int (l, "saveopen_w", gtk_spin_button_get_value_as_int (sb_saveopen_w));  
  // l = add_to_glist_combined_int (l, "saveopen_h", gtk_spin_button_get_value_as_int (sb_saveopen_h));  
   l = add_to_glist_combined_int (l, "tab_size", gtk_spin_button_get_value_as_int (sb_tab_size));  
 
   glist_save_to_file (l, confile.tea_rc);

   glist_strings_free (l);
   confile_reload ();
   doc_update_all();
   update_enc_menu();
}


static GtkWidget* wnd_options_encoding (void)
{
  GtkWidget *wnd = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (wnd);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (wnd), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
 
  GtkWidget *page = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (page);
  gtk_scrolled_window_add_with_viewport (wnd, page);

  GtkWidget *fr1 = gtk_frame_new (_("Defaults"));   
  gtk_widget_show (fr1);
  gtk_box_pack_start (page, fr1, FALSE, FALSE, 1);

  ent_default_charset = tea_combo (page, confile.iconv_encs, _("Default charset pour fichier ouvert"), confile.default_charset);
  ent_def_filesave_charset = tea_combo (page, confile.gl_save_charsets, _("Default charset pour fichier sauvegardé sous"), confile.def_filesave_charset);
 
  fr1 = gtk_frame_new (_("Misc"));   
  gtk_widget_show (fr1);
  gtk_box_pack_start (page, fr1, FALSE, FALSE, 1);
 
  ent_rtf_enc = tea_text_entry (page, _("Default charset pour RTF"), confile.rtf_enc);  
 
  GtkWidget *fr2 = gtk_frame_new (_("Autodetect"));   
  gtk_widget_show (fr2);
 
  gtk_box_pack_start (page, fr2, FALSE, FALSE, 1);
  
  cb_enc_det_cp1251 = tea_checkbox (page, _("CP 1251"), confile.enc_det_cp1251); 
  cb_enc_det_koi8r = tea_checkbox (page, _("KOI8-R"), confile.enc_det_koi8r);
  cb_enc_det_koi8u = tea_checkbox (page, _("KOI8-U"), confile.enc_det_koi8u);
  cb_enc_det_866 = tea_checkbox (page, _("DOS 866"), confile.enc_det_866);

  cb_enc_det_finnish = tea_checkbox (page, _("Finnish"), confile.enc_det_finnish);
  cb_enc_det_german = tea_checkbox (page, _("German"), confile.enc_det_german);
  cb_enc_det_serbian = tea_checkbox (page, _("Serbian"), confile.enc_det_serbian);
  cb_enc_det_latvian = tea_checkbox (page, _("Latvian"), confile.enc_det_latvian);
  cb_enc_det_polish = tea_checkbox (page, _("Polish"), confile.enc_det_polish);
  cb_enc_det_portuguese = tea_checkbox (page, _("Portuguese"), confile.enc_det_portuguese);
  cb_enc_det_slovak = tea_checkbox (page, _("Slovak"), confile.enc_det_slovak);
  cb_enc_det_slovenian = tea_checkbox (page, _("Slovenian"), confile.enc_det_slovenian);
  cb_enc_det_spanish = tea_checkbox (page, _("Spanish"), confile.enc_det_spanish);  
  cb_enc_det_turkish = tea_checkbox (page, _("Turkish"), confile.enc_det_turkish);  

  return wnd;
}


static GtkWidget* wnd_options_commands (void)
{
  GtkWidget *page = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (page);

  ent_ext_pic_editor = tea_text_entry (page, _("Éditeur d'image externe"), confile.ext_pic_editor);
  ent_ext_pic_viewer = tea_text_entry (page, _("Visionneuse d'image externe"), confile.ext_pic_viewer);
  ent_cm_mplayer =  tea_text_entry (page, _("Lancez MPlayer avec les sous-titres"), confile.cm_mplayer);
 
  return page;
}


static GtkWidget* wnd_options_limits (void)
{
  GtkWidget *page = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (page);

  //sb_logmemo_lines_max = tea_spinbutton (page, _("Logmemo nombre de lignes limite"), confile.logmemo_lines_max);
  //sb_famous_history_max = tea_spinbutton (page, _("Limite de l'historique de saisie de texte"), confile.famous_history_max);
  sb_max_recent_items = tea_spinbutton (page, _("Max de fichiers récents"), confile.max_recent_items); 

  return page;
}


static GtkWidget* wnd_options_functions (void)
{
  GtkWidget *page = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (page);
  ent_date_time = tea_text_entry (page, _("Format de la date et de l'heure"), confile.date_time);
  ent_fmt_color_function = tea_text_entry (page, _("Le format de la fonction Couleur"), confile.fmt_color_function);

  return page;
}


static GtkWidget* wnd_options_interface (void)
{
  GtkWidget *page = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (page);
  
  //sb_saveopen_w = tea_spinbutton (page, _("Enregistrer / Ouvrir largeur des boîtes de dialogue pour cents"), confile.saveopen_w);
  //sb_saveopen_h = tea_spinbutton (page, _("Enregistrer / Ouvrir la hauteur des boîtes de dialogue pour cents"), confile.saveopen_h);
  cb_main_wnd_show_full_path = tea_checkbox (page, _("Afficher le chemin complet dans le titre de la fenêtre"), confile.main_wnd_show_full_path); 
  //cb_do_show_main_toolbar = tea_checkbox (page, _("Afficher la barre d'outils principale"), confile.do_show_main_toolbar); 

  sb_thumb_width = tea_spinbutton (page, _("Largeur de l'image thumbnail"), confile.thumb_width);
  sb_thumb_height = tea_spinbutton (page, _("Hauteur de l'image thumbnail"), confile.thumb_height);

  return page;
}


static GtkWidget* wnd_options_switches (void)
{
  GtkWidget *page = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (page);

  cb_start_with_recent_file = tea_checkbox (page, _("Lancer Griffon avec un fichier récent"), confile.start_with_recent_file); 
  cb_start_with_blank_file = tea_checkbox (page, _("Lancer Griffon avec un fichier vide"), confile.start_with_blank_file); 
  cb_do_det_scripts_by_content = tea_checkbox (page, _("Déterminer la coloration syntaxique par le contenu du fichier"), confile.do_det_scripts_by_content); 
  cb_xhtml_mode = tea_checkbox (page, _("Mode XHTML pour des Markup"), confile.xhtml_mode); 
  //cb_show_hidden_files = tea_checkbox (page, _("Show hidden files in Kwas"), confile.show_hidden_files); 
  cb_use_snippets = tea_checkbox (page, _("Utiliser les snippets"), confile.use_snippets); 
  cb_use_ext_image_viewer = tea_checkbox (page, _("Utiliser le visualisateur d'image externe"), confile.use_ext_image_viewer);
  cb_do_hl_on_fileopen = tea_checkbox (page, _("Coloration de la syntaxe à l'ouverture du fichier"), confile.do_hl_on_fileopen);
  cb_do_backup = tea_checkbox (page, _("Fichier backup"), confile.do_backup);
  cb_show_line_nums = tea_checkbox (page, _("Afficher les numéros de ligne"), confile.show_line_nums);
  cb_word_wrap = tea_checkbox (page, _("Word wrap"), confile.word_wrap);
  cb_scan_for_links_on_doc_open = tea_checkbox (page, _("Analyser les liens à l'ouverture de fichier"), confile.scan_for_links_on_doc_open);

  return page;
}


static GtkWidget* wnd_options_confirmations (void)
{
  GtkWidget *page = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (page);
  
  cb_prompt_on_not_saved = tea_checkbox (page, _("M'avertir avant la fermeture d'un fichier modifié"), confile.prompt_on_not_saved); 
  cb_prompt_on_file_exists = tea_checkbox (page, _("Ecraser le fichier existant"), confile.prompt_on_file_exists); 
  //cb_warn_about_aliens = tea_checkbox (page, _("Warn me about those little green men in a toilet"), confile.warn_about_aliens); 
 
  return page;
}


static void cb_backup_config (GtkButton *button,
                              gpointer user_data)
{
  gchar *f = g_strconcat (confile.tea_rc, ".bak", NULL);
  copy_file (confile.tea_rc, f);
  g_free (f);
}


static void cb_restore_config (GtkButton *button,
                              gpointer user_data)
{
  gchar *f = g_strconcat (confile.tea_rc, ".bak", NULL);
  copy_file (f, confile.tea_rc);
  g_free (f);
  confile_reload ();
  doc_update_all();
  update_enc_menu();
  dlg_info (wnd_options, _("Configuration restaurée, s'il vous plaît fermez et rouvrez la fenêtre Préférences."), NULL);  
}

static void cb_config_reset (GtkButton *button,
                             gpointer user_data)
{
   if (unlink (confile.tea_rc) == 0 )
      {
       confile_reload ();
       doc_update_all();
       update_enc_menu();
       dlg_info (wnd_options, _("Configuration remis à zéro par défaut, s'il vous plaît fermez et rouvrez la fenêtre Préférences."), NULL);  
      }  
}


static GtkWidget* wnd_options_maintenance (void)
{
  GtkWidget *page = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (page);
  
  gtk_box_set_homogeneous (page, FALSE);

  GtkWidget *b = tea_button_at_box (page, _("Sauvegarde de la configuration actuelle" ), cb_backup_config, NULL);
  b = tea_button_at_box (page, _("Restaurer une configuration" ), cb_restore_config, NULL);
  b = tea_button_at_box (page, _("Réinitialiser config par défaut" ), cb_config_reset, NULL);
    
  return page;
}


static GtkWidget* wnd_options_colors (void)
{
  GtkWidget *notebook = gtk_notebook_new ();         
  gtk_widget_show (notebook);

  GtkWidget *page = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (page);

  gtk_notebook_append_page (notebook, page, gtk_label_new (_("Editeur")));
 
  ent_text_foreground = tea_color_selector (page, _("Avant-plan du texte"), confile.text_foreground);
  ent_text_background = tea_color_selector (page, _("Arrière-plan du texte"), confile.text_background);
  ent_text_sel_foreground = tea_color_selector (page, _("Plan sélectionné"), confile.text_sel_foreground);
  ent_text_sel_background = tea_color_selector (page, _("Arrière-plan sélectionnée"), confile.text_sel_background);
  ent_tag_spellcheck = tea_color_selector (page, _("Marques de vérification orthographique"), confile.tag_spellcheck);
  
  page = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (page);
 /* gtk_notebook_append_page (notebook, page, gtk_label_new (_("Coloration syntaxique")));
 
  ent_tag_comment = tea_color_selector (page, _("Commentaires"), confile.tag_comment);
  ent_tag_identifier = tea_color_selector (page, _("Identificateurs"), confile.tag_identifier);
  ent_tag_digit = tea_color_selector (page, _("Chiffres"), confile.tag_digit); 
  ent_tag_string = tea_color_selector (page, _("Chaîne de caractère"), confile.tag_string);
  ent_tag_html_tag = tea_color_selector (page, _("HTML tags"), confile.tag_html_tag);
  ent_tag_preprocessor = tea_color_selector (page, _("Preprocessor"), confile.tag_preprocessor);
  ent_tag_type = tea_color_selector (page, _("Types"), confile.tag_type);

  page = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (page);*/
  gtk_notebook_append_page (notebook, page, gtk_label_new (_("IDE")));
 
  ent_tag_color_lm_error_fg = tea_color_selector (page, _("Errors avant-plan (logmemo)"), confile.tag_color_lm_error_fg);
  ent_tag_color_lm_error_bg = tea_color_selector (page, _("Errors arrière-plan du texte (logmemo)"), confile.tag_color_lm_error_bg);

  return notebook ;
}


static GtkWidget* wnd_options_fonts (void)
{
  GtkWidget *page = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (page);

  ent_editor_font = tea_font_selector (page, _("Editeur font"), confile.editor_font); 

  ent_tag_comment_font = tea_font_selector (page, _("Commentaires font"), confile.tag_comment_font); 
  ent_tag_identifier_font = tea_font_selector (page, _("Identificateurs font"), confile.tag_identifier_font); 
  ent_tag_digit_font = tea_font_selector (page, _("Chiffres font"), confile.tag_digit_font); 
  ent_tag_string_font = tea_font_selector (page, _("Chaîne de caractère"), confile.tag_string_font); 
  ent_tag_html_tag_font = tea_font_selector (page, _("HTML tags font"), confile.tag_html_tag_font); 
  ent_tag_preprocessor_font = tea_font_selector (page, _("Preprocessor font"), confile.tag_preprocessor_font); 
  ent_tag_type_font = tea_font_selector (page, _("Types font"), confile.tag_type_font); 
  
  return page;
}


static GtkWidget* wnd_options_browsers (void)
{
  GtkWidget *page = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (page);
  ent_cm_opera = tea_text_entry (page, "Opera", confile.cmd_Opera);
  ent_cm_konqueror = tea_text_entry (page, "Konqueror", confile.cmd_Konqueror);
  ent_cm_firefox = tea_text_entry (page, "Firefox", confile.cmd_Firefox);
  ent_cm_mozilla = tea_text_entry (page, "Mozilla",  confile.cmd_Mozilla);
  ent_cm_links = tea_text_entry (page, "Links", confile.cmd_Links); 
  ent_cm_elinks = tea_text_entry (page, "Elinks", confile.cmd_ELinks);
  ent_cm_dillo = tea_text_entry (page, "Dillo", confile.cmd_Dillo);
  ent_cm_galeon = tea_text_entry (page, "Galeon", confile.cmd_Galeon);
  ent_cm_epiphany = tea_text_entry (page, "Epiphany", confile.cmd_Epiphany); 
  ent_cm_other = tea_text_entry (page, "Other", confile.cmd_Other);
  ent_cm_lynx = tea_text_entry (page, "Lynx", confile.cmd_Lynx);
  ent_cm_manual_browser = tea_text_entry (page, _("Browser for the manual"), confile.cmd_def_doc_browser);
  cb_use_def_doc_browser = tea_checkbox (page, _("Utilisez votre navigateur"), confile.use_def_doc_browser); 

  return page;
}


static GtkWidget* wnd_options_editor (void)
{
  GtkWidget *page = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (page);
  sb_tab_size = tea_spinbutton (page, _("Taille des tabulations en espaces"), confile.tab_size);
  cb_ins_spaces_on_tab_press = tea_checkbox (page, _("Insérer des espaces sur la touche TAB"), confile.ins_spaces_on_tab_press);
  cb_use_auto_indent = tea_checkbox (page, _("Indentation automatique"), confile.use_auto_indent);
	cb_use_infotext = tea_checkbox (page, _("Afficher les informations ESPACE,TAB,RETOUR CHARIOT..."), confile.use_infotext);
	cb_use_spellcheck = tea_checkbox (page, _("Activer la correction d'orthographe"), confile.use_spellcheck);

  return page;
}


static GtkWidget* wnd_options_paths (void)
{
  GtkWidget *page = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (page);
  ent_def_save_dir = tea_dir_selector (page, _("Default file saving directory"), confile.def_save_dir);
  cb_use_def_save_dir = tea_checkbox (page, _("Use default saving directory"), confile.use_def_save_dir);
  ent_def_open_dir = tea_dir_selector (page, _("Default file opening directory"), confile.def_open_dir);
  cb_use_def_open_dir = tea_checkbox (page, _("Use default file opening directory"), confile.use_def_open_dir);
  
  return page;
}


static GtkWidget* wnd_options_coauthor (void)
{
  GtkWidget *page = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (page);

  //cb_use_autocomp = tea_checkbox (page, _("Automatic word completion"), confile.use_autocomp);
  //sb_autocomp_wordlen_min = tea_spinbutton (page, _("Mininum autocompletion word length"), confile.autocomp_wordlen_min);
  //sb_autocomp_list_items_max = tea_spinbutton (page, _("Autocompletion list items maximum"), confile.autocomp_list_items_max);
  cb_do_autorep = tea_checkbox (page, _("Remplacement automatique"), confile.do_autorep);
		cb_use_textcompbloc = tea_checkbox (page, _("Autocompletion des bloc et balises {} () ..."), confile.use_textcompbloc);
  return page;
}



GtkWidget* wnd_options_create (void)
{
  wnd_options = gtk_window_new (GTK_WINDOW_TOPLEVEL);

  gtk_window_set_title (GTK_WINDOW (wnd_options), _("Options"));
  GtkWidget *vbox1 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox1);
  gtk_container_add (GTK_CONTAINER (wnd_options), vbox1);

  GtkWidget *notebook = gtk_notebook_new ();         
  gtk_notebook_set_tab_pos (notebook, GTK_POS_LEFT);

  gtk_widget_show (notebook);

  gtk_container_add (GTK_CONTAINER (vbox1), notebook);

  gtk_notebook_append_page (notebook, wnd_options_switches (), gtk_label_new (_("Principale")));
  gtk_notebook_append_page (notebook, wnd_options_encoding (), gtk_label_new (_("Encodage")));
  gtk_notebook_append_page (notebook, wnd_options_functions (), gtk_label_new (_("Fonctions")));
  gtk_notebook_append_page (notebook, wnd_options_interface (), gtk_label_new (_("Interface")));
  gtk_notebook_append_page (notebook, wnd_options_limits (), gtk_label_new (_("Limites")));
  gtk_notebook_append_page (notebook, wnd_options_fonts (), gtk_label_new (_("Fonts")));
  gtk_notebook_append_page (notebook, wnd_options_editor (), gtk_label_new (_("Editeur")));
  gtk_notebook_append_page (notebook, wnd_options_browsers (), gtk_label_new (_("Navigateurs")));
  gtk_notebook_append_page (notebook, wnd_options_colors (), gtk_label_new (_("Couleurs")));
  gtk_notebook_append_page (notebook, wnd_options_commands (), gtk_label_new (_("Commandes")));
  gtk_notebook_append_page (notebook, wnd_options_paths (), gtk_label_new (_("Paths")));
  gtk_notebook_append_page (notebook, wnd_options_coauthor (), gtk_label_new (_("Complémentation")));
  gtk_notebook_append_page (notebook, wnd_options_confirmations (), gtk_label_new (_("Confirmations")));
  gtk_notebook_append_page (notebook, wnd_options_maintenance (), gtk_label_new (_("Maintenance")));

  gtk_notebook_set_current_page (notebook, confile.last_prefs_tab);

 /* g_signal_connect ((gpointer) notebook, "switch_page",
                    G_CALLBACK (on_kwas_notebook_switch_page),
                    NULL);*/

  GtkWidget *hbox1 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox1);
  gtk_container_add (GTK_CONTAINER (vbox1), hbox1);

  GtkWidget *bt_close = gtk_button_new_with_label (_("Fermer"));
  gtk_widget_show (bt_close);
  gtk_container_add (GTK_CONTAINER (hbox1), bt_close);
  g_signal_connect (bt_close, "clicked", G_CALLBACK (cb_on_bt_close), wnd_options);

  GtkWidget *bt_apply = gtk_button_new_with_label (_("Sauvegarder et aplliquer"));
  gtk_widget_show (bt_apply);
  gtk_container_add (GTK_CONTAINER (hbox1), bt_apply);
  g_signal_connect (bt_apply, "clicked", G_CALLBACK (cb_on_bt_apply), wnd_options);

  gtk_window_set_position (wnd_options, GTK_WIN_POS_CENTER);   
 // gtk_window_set_modal (wnd_options, TRUE);

  gtk_widget_show (wnd_options);
  return wnd_options;
}
