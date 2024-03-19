/* Ed, ed_on_f_ch */
#include "ed.h"
#include "ed_ins.h"
/* ed_mv_begin_of_row, ed_mv_down, ed_mv_right */
#include "ed_mv.h"
/* row_empty, row_ins, rows_ins */
#include "row.h"

void
ed_ins(Ed *const ed, const char ch)
{
	row_ins(
		&ed->rows.arr[ed->offset_row + ed->cur.y],
		ed->offset_col + ed->cur.x,
		ch
	);
	ed_mv_right(ed);
	ed_on_f_ch(ed);
}

void
ed_ins_break(Ed *const ed)
{
	rows_break(&ed->rows, ed->offset_row + ed->cur.y, ed->offset_col + ed->cur.x);
	ed_mv_begin_of_row(ed);
	ed_mv_down(ed);
}

void
ed_ins_row_below(Ed *const ed)
{
	ed_mv_begin_of_row(ed);
	ed_mv_down(ed);
	rows_ins(&ed->rows, ed->offset_row + ed->cur.y, row_empty());
	ed_on_f_ch(ed);
}

void
ed_ins_row_top(Ed *const ed)
{
	ed_mv_begin_of_row(ed);
	rows_ins(&ed->rows, ed->offset_row + ed->cur.y, row_empty());
	ed_on_f_ch(ed);
}