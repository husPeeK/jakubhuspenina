#ifndef hudba_h
#define hudba_h

#define is 50
#define nazev 50

struct t_album {
	char i[is];
	char n[nazev];
	int rok;
	struct t_album* dalsi;
	
};
void add(const char* i, const char* n, int rok, struct t_album** seznam);
void del(const char* i, struct t_album** seznam);
void print(const struct t_album* seznam);

#endif