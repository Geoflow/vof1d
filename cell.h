#ifndef CELL_H
#define CELL_H


class Cell
{
public:

	Cell(int i, double a, double b);

	//METHODES
	double get_cnt() const;
	double get_ctg() const;
	double get_ctd() const;
	int get_ind() const;

	void set_cnt(double c);
	void set_ctg(double g);
	void set_ctd(double d);
	void set_ind(int i);

private:
	//ATTRIBUTS
	int m_ind ; // indice de la cellule
	double m_a ; //frontiere droite du domaine
	double m_b ; // frontiere gauche du domaine

	double m_cnt = 0.; // point centre
	double m_ctg = 0.; //interface gauche
	double m_ctd = 0.; //interface droite
    double m_h=0;

};

#endif // CELL_H
