/* Ed */
#include "ed.h"
/* ed_sig_reg */
#include "ed_sig.h"
#include "ed_term.h"
/* term_disable_raw_mode, term_enable_raw_mode, term_get_win_size, term_init */
#include "term.h"

void
ed_term_deinit(void)
{
	term_disable_raw_mode();
}

void
ed_term_init(Ed *const ed, const int ifd, const int ofd)
{
	term_init(ifd, ofd);
	term_enable_raw_mode();
	/* Update window size and register signal handlers */
	term_get_win_size(&ed->win_size);
	ed_sig_reg(ed);
}