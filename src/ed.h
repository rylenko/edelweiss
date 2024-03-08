#ifndef _ED_H
#define _ED_H

/* Returns `1` if we need to quit the editor, otherwise `0`. */
char ed_need_to_quit(void);

/* Opens new file in the editor. */
void ed_open(const char *);

/* Refreshes the screen with editor's state. */
void ed_refresh_scr(void);

/* Waits and processes key presses from terminal's input. */
void ed_wait_and_proc_key(void);

#endif /* _EDITOR_H */