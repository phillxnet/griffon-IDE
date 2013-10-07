/***************************************************************************
                          interface.h  -  description
                             -------------------
    begin                : Mon Dec 1 2003
 ***************************************************************************/

#include <webkit/webkit.h>
#include <gtksourceview/completion-providers/words/gtksourcecompletionwords.h>

typedef struct _TestProvider TestProvider;
typedef struct _TestProviderClass TestProviderClass;

static GtkSourceCompletionWords *word_provider,*word_provider2,*word_provider3;
static TestProvider *fixed_provider;
static TestProvider *random_provider;

struct _TestProvider
{
	GObject parent;

	GList *proposals;
	gint priority;
	gchar *name;

	GdkPixbuf *icon;

	/* If it's a random provider, a subset of 'proposals' are choosen on
	 * each populate. Otherwise, all the proposals are shown. */
	guint is_random : 1;
};

typedef struct
{
GtkWidget *vbox2, *scrolledwindow3;
GtkWidget *vte_add;
GtkWidget *label_term;
GtkWidget * hbox_term_tab;
GtkWidget * image_term_tab;
GtkWidget * button_close_term;
gint num_tab;
} term_page;

GtkListStore *model_entry;

typedef struct contact {
  char *name;
} contact;

typedef enum {
  CONTACT_NAME = 0
} ContactCol;

GtkListStore *model_entry_http;

typedef struct contact_http {
  char *name;
} contact_http;

typedef enum {
  CONTACT_NAME_HTTP = 0
} ContactCol_http;

GtkListStore *model_entry_http2;

typedef struct contact_http2 {
  char *name;
} contact_http2;

typedef enum {
  CONTACT_NAME_HTTP2 = 0
} ContactCol_http2;

void switch_filechooser ();

//************** VTE MENU
GtkWidget *menu_vte;
WebKitWebView *webView, *webView_myadmin, *webView_source,*webView_myadmin_traduc,*webView_myadmin_aide,*webView_editor;
char liste_mount[1000];
GtkSourceBuffer *buffer_api, *buffer_note, *buffer_scan, *log_memo_textbuffer, *buffer_include, *buffer_projet;
GtkWidget *sr_wnd,*win_tips_autocomp;
GtkWidget *scrolledWindow_editor;
GtkWidget *tea_main_window;
GtkWidget *mainvbox,*filechooserwidget2;
GtkWidget *cmb_famous, *hbox_bar;   
GtkWidget *ent_search;
GtkWidget *cmb_famous2;   
GtkWidget *ent_search2;
GtkWidget *dlg_colorsel;
GtkNotebook *notebook1;
GtkNotebook *notebook3;
GtkWidget *menubar1;
GtkWidget *mni_file_menu;
GtkWidget *mni_file_configs_menu;
GtkWidget *mni_autocomp;
GtkWidget *mni_ide;
GtkWidget *mni_ide_menu;
GtkWidget *mni_view_menu;
GtkWidget *mni_recent_list;
GtkWidget *mni_recent_menu;
GtkWidget *mni_sessions;
GtkWidget *mni_sessions_menu;
GtkWidget *mni_templates;
GtkWidget *mni_templates_menu;
GtkWidget *mni_morse_menu;
GtkVPaned *vpaned1;
GtkWidget *vbox2;
GtkWidget *scrolledwindow3;
GtkWidget *tv_logmemo;
GtkWidget *mni_edit_menu;
GtkWidget *mni_edit_undo;
GtkWidget *mni_edit_redo;
GtkWidget *mni_hl_mode_menu,*mni_theme_menu;
GtkWidget *mni_markup_menu;
GtkWidget *mni_insert_doctype_menu;
GtkWidget *mni_insert_char_entities_menu;
GtkWidget *mni_format_menu;
GtkWidget *mni_quest_menu;
GtkWidget *mni_ins_menu;
GtkWidget *mni_eol_menu;
GtkWidget *mni_savedifferent_menu;
GtkWidget *mni_opendifferent_menu;
GtkWidget *mni_markup_header_menu;
GtkWidget *mni_markup_header_item;
GtkWidget *mni_markup_align;
GtkWidget *mni_markup_align_menu;
GtkWidget *mni_what_menu;
GtkWidget *mni_functions;
GtkWidget *mni_spellcheck_menu;
GtkWidget *mni_spellcheck;
GtkWidget *mni_user_menu_menu;
GtkWidget *mni_user_menu;
GtkWidget *mni_table_menu;
GtkWidget *mni_functions_menu;
GtkWidget *mni_functions_case;
GtkWidget *mni_functions_case_menu;
GtkWidget *mni_filter_menu;
GtkWidget *mni_functions_number;
GtkWidget *mni_functions_number_menu;
GtkWidget *mni_functions_string;
GtkWidget *mni_functions_string_menu;
GtkWidget *mni_snippets_menu;
GtkWidget *mni_snippets;
GtkWidget *mni_html_menu;
GtkWidget *mni_align_menu;
GtkWidget *mni_co_menu;
GtkWidget *mni_co;
GtkWidget *mni_bro_menu;
GtkWidget *mni_links;
GtkMenuItem *mni_links_menu;
GtkWidget *mni_sort_menu;
GtkWidget *notebook2;
GtkWidget *mni_tabs;
GtkWidget *mni_tabs_menu;
GtkWidget *notebook_down, *notebook_term;
GtkWidget *mni_utils_menu;
GtkWidget *mni_utils_cc_menu;
GtkWidget *mni_utils_unitaz_menu;
GtkWidget *mni_bookmarks_root;
GtkWidget *mni_bookmarks_menu;
GtkWidget *mni_bookmarks_cc_menu;
GtkWidget *mni_view_menu;
GtkWidget *tb_main_toolbar;
GtkWidget *mni_nav_menu;
GtkWidget *statusbar1;
GtkAccelGroup *accel_group;
GtkTextTag *temp_tag;
GtkTextTag *tag_lm_error;
GtkWidget* create_tea_main_window (void);
void statusbar_msg (const gchar *s);
GtkWidget* splash_screen (void);
GtkWidget* icon_affiche_bug (void);
GtkWidget* icon_affiche_net (void);
GtkWidget* icon_affiche_stop (void);
GtkWidget* icon_affiche_ok (void);
GtkWidget* man_page (void);
GtkTextBuffer *buffer_bug;
GtkWidget *open_tools(void);
GtkWidget *close_tools(void);
GtkWidget* clear_note (void);
GtkWidget* file_ok_sel (void);
GtkWidget* create_about1 (void);
GtkWidget* create_custom_win (void);
void start_custom (void);
static GtkWidget * create_view_and_model_help (void);
static GtkWidget * create_view_and_model_myadmin (void);
void focus_term ();
void focus_web ();
void todo_list ();
GtkWidget *entry_web;
void  on_changed_myadmin(GtkWidget *widget, gpointer statusbar);
void  myadmin();
void no_onglet_open();
GtkWidget* doc_window (void);
void  no_onglet_open();
void web_current_file();
void  insert_img_autoconf_var();
void  insert_img_autoconf_mot();
void  insert_img_autoconf_fonc();
void  fin_de_scroll_pos() ;
void  icon_log_logmemo();
void  icon_list_logmemo();
void  icon_stop_logmemo();
void  icon_ok_logmemo();
void  icon_man_logmemo();
GtkWidget* icon_affiche_save (void);
GtkWidget* icon_affiche_nosave (void);
void  controle_save() ;
void  icon_save_logmemo();
void  icon_nosave_logmemo();
GtkWidget* version_window (void);
static GtkTreeModel * create_and_fill_model_sftp (void);
static GtkWidget * create_view_and_model_sftp (void);
void  on_changed_sftp(GtkWidget *widget, gpointer statusbar);
gchar *sshadd;
void  sftp_reload();
void  ftp_reload();
void  on_changed_ftp(GtkWidget *widget, gpointer statusbar);
static GtkTreeModel * create_and_fill_model_ftp (void);
static GtkWidget * create_view_and_model_ftp (void);
void  vide_configuration_ftp();
void  vide_configuration_sftp();
GtkWidget* rapport_window (void);
GtkTreeSelection *selection_sftp ;
GtkTreeSelection *selection_ftp ;
void  switch_html_page();
void  controle_save_page_icon_no();
void  controle_save_page_icon();
GtkListStore * create_liststore();
void add_to_list(gchar *str,gchar *str2);
void clear_list_include ();
void on_changed_scan (GtkWidget *widget);
void add_to_list_fc(gchar *str,gchar *str2);
void add_to_list_var(gchar *str,gchar *str2);
void insert_image_web();
GtkListStore *create_liststore_book();
void add_to_list_book(gchar *str,gchar *str2);
void on_changed_book (GtkWidget *widget);
static GtkNotebook*
window_creation_function (GtkNotebook *source_notebook,GtkWidget   *child,gint         x,gint         y,gpointer     data);
//GtkWidget* window_creation_function ();
GtkWidget* close_tools2 (void);
void del_book() ;
void google_search();
void google_traduction_fr_en();
void google_traduction_en_fr();
void enter_web (GdkEventKey *event, gpointer data);
void myadmin_reload ();
void myadmin_back ();
void myadmin_forward ();
void myadmin_stop ();
void miniweb_reload ();
void miniweb_back ();
void miniweb_forward ();
void miniweb_stop ();
void enter_myweb (GdkEventKey *event, gpointer data);
void myadmin_get_url ();
void miniweb_get_url ();
void miniweb_source_mode_get_url ();
void miniweb_view_mode_get_url ();
void myadmin_source_mode_get_url ();
void myadmin_view_mode_get_url ();
void new_terminal ();
void on_button_close_term ();
void myadmin_bookmark_off ();
void myadmin_bookmark_on ();
void next_term ();
void prev_term ();
void window_debug ();
void run_debug ();
void clear_debug ();
void new_terminal_ssh (gchar *serveur,gchar *user);
void new_dir_cmd ();
void new_file_cmd ();
void new_web_window ();
void new_web_window_mini ();
void new_file_log_edit ();
void new_file_term_edit (GtkWidget *tv,GdkEventButton *event,  gpointer user_data);
static gboolean myadmin_new_window (WebKitWebView             *web_view,
                                                        WebKitWebFrame            *frame,
                                                        WebKitNetworkRequest      *request,
                                                        WebKitWebNavigationAction *navigation_action,
                                                        WebKitWebPolicyDecision   *policy_decision,
                                                        gpointer                   user_data);
static gboolean web_new_w_click(WebKitWebView *web_view,gpointer       user_data);
WebKitWebView * web_new_w_click_go(WebKitWebView  *web_view,
                                                        WebKitWebFrame *frame,
                                                        gpointer        user_data);

void myadmin_reload_win (GtkToolItem *tool,gpointer user_data);
void myadmin_back_win (GtkToolItem *tool,gpointer user_data);
void myadmin_forward_win (GtkToolItem *tool,gpointer user_data);
void myadmin_stop_win (GtkToolItem *tool,gpointer user_data);
void myadmin_source_mode_get_url_win (GtkToolItem *tool,gpointer user_data);
void myadmin_view_mode_get_url_win (GtkToolItem *tool,gpointer user_data);
void enter_myweb_win (GtkWidget* entry, gpointer user_data);
void myadmin_get_url_win (WebKitWebView  *web, WebKitWebFrame *frame,gpointer user_data);
void griffon_notify (gchar* txt);
void add_to_list_err(gchar *str,gchar *str2);
static void download_requested_cb(WebKitWebView *web_view, WebKitDownload *download, gpointer user_data);
static void download_status_cb(GObject* object, GParamSpec* pspec, gpointer data);
static gboolean
navigation_policy_decision_requested_cb(WebKitWebView* web_view,
                                        WebKitWebFrame* web_frame,
                                        WebKitNetworkRequest* request,
                                        WebKitWebNavigationAction* action,
                                        WebKitWebPolicyDecision* decision,
                                        gpointer data);
