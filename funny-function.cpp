// What is preffered

/*
   trzy funkcje
   */
int printA() {
	std::cout << 'A';
}
int printB() {
	std::cout << 'B';
}
int printC() {
	std::cout << 'C';
}


int  main() {
	printA();
	printB();
	printC();
}

/*
   sparametryzowana funkcja
   */
int printLetter(int x) {
	switch(x) {
		case 0 : std::cout << 'A';
		case 1 : std::cout << 'B';
		case 2 : std::cout << 'C';
	}
}

int  main() {
	printLetter(0);
	printLetter(1);
	printLetter(2);
}
/*************/
/* jesli z gory wiem ze parametry beda trzy i wiecej nigdy nie bedzie to robie trzy oddzielne funkcje
   jesli parametrow moze byc wiecej np 20: a b c d e f g to parametryzujemy funkcje i printujemy tak
         jak chcial Pac
		 ale nawet w tym  przypadku lepiej jest byc sprytnym i parametr wykorzystac do zaindeksowania
				tego co ma byc wypisane
   */
int printLetter(int x) {
	std::cout << (char)('A' + x);
}

int main() {
	printLetter(0);
	printLetter(1);
	printLetter(2);
}

/*
   W przypadku naszego loggera switch zaproponowany przez Pac jest 'drogi' tzn pare taktow zegara zostanie zuzytych na sprawdzenie parametru i skok do odpowiedniego kejsa w switchu.
   Oto moja propozycja jesli juz naprawde koniecznie chcemy sparametryzowac (a tak jak mi sie wydaje
   zadne parametryzowanie tu nie jest konieczne po prostu trzy oddzielne funkcje i koniec
   */
int printA() {
	std::cout << 'A';
}
int printB() {
	std::cout << 'B';
}
int printC() {
	std::cout << 'C';
}

int ()*printLetter[3] = {printA, printB, printC};

int main() {
	printLetter[0]();
	printLetter[1]();
	printLetter[2]();
	return 0;
}


/*
Dodam jeszcze ze to co wlasnie napisalem mozna zrobic bez tablicy wskaznikow na funkcje
korzystajac z dziedziczenia; dziedziczenie to sa ukryte wskazniki na funkcje ktorymi sie zongluje:
w tym przypadku wygladaloby to jakos tak:
*/

struct Interfejsik {
	virtual printLetter() = 0;
};
struct A : Interfejsik {
	virtual printLetter() override {std::cout << "A";}
};
struct B : Interfejsik {
	virtual printLetter() override {std::cout << "B";}
};
struct C : Interfejsik {
	virtual printLetter() override {std::cout << "C";}
};

A a;
B b;
C c;

Interfejsik *interfejsik[] = {&a, &b, &c};

int main() {
	interfejsik[0]->printLetter();
	interfejsik[1]->printLetter();
	interfejsik[2]->printLetter();
}

/*
Wniosek: switch jest rozwiazaniem najgorszym wydajnosciowo i generujacym najdluzszy blok kodu do analizy
No ale tak to jest - na bledach najlepiej sie uczyc.
*/
