#ifndef BASEPRINT_H
#define BASEPRINT_H

class BasePrint {
	private:
		/* Value to Print */
		double value;

	public:
		/* Constructors */
		BasePrint();
		BasePrint(double x){value = x;}; ;
		
		/* Pure Virtual Print Function */
		virtual void print() = 0;

		double getVal(){return value;};
};

#endif
