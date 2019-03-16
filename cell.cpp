#include "cell.h"

Cell::Cell( int i, double a, double b): m_ind(i), m_a(a), m_b(b)
{ // initialise la cellule

}

double Cell::get_cnt() const
{
	return m_cnt;
}

double Cell::get_ctg() const
{
	return m_ctg;
}

double Cell::get_ctd() const
{
	return m_ctd;
}

int Cell::get_ind() const
{
	return m_ind;
}

void Cell::set_cnt(double c)
{
	m_cnt = c;
}

void Cell::set_ctg(double g)
{
	m_ctg = g;
}

void Cell::set_ctd(double d)
{
	m_ctd = d;
}

void Cell::set_ind(int i)
{
	m_ind = i;
}
