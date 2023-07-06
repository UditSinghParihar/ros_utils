#include <bits/stdc++.h>

using namespace std;


class Apple{
private:
	int x;
	int y;

public:
	Apple(int x, int y){
		this->x = x;
		this->y = y;
	}

	pair<int, int> get_value(void){
		return make_pair(x, y);
	}

	void set_value(int x, int y){
		this->x = x;
		this->y = y;
	}
};


int main(int argc, char** argv){
	int a = 10;
	int *ap = &a;
	fprintf(stdout, "a = %d\n", *ap);

	// shared_ptr<int> ptr(&a);
	// fprintf(stdout, "a = %d\n", *ptr);


	Apple app(2, 3);
	app.set_value(20, 30);


	pair<int, int> p = app.get_value();
	fprintf(stderr, "Values: %d %d\n", p.first, p.second);


	Apple *app_ptr = new Apple(-1, -2);
	p = app_ptr->get_value();
	fprintf(stderr, "Values: %d %d\n", p.first, p.second);	


	shared_ptr<Apple> shptr(new Apple(5, 6));
	p = shptr->get_value();
	fprintf(stderr, "Values: %d %d\n", p.first, p.second);


	return 0;
}