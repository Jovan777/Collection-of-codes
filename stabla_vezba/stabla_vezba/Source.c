#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct cvor {

	int broj;
	struct cvor* levo, * desno;

}Cvor;

typedef Cvor* Stablo; //niz cvorova, sustinski stablo


Stablo stvori() {

	return NULL;
}

int vel(Stablo stb) {

	return stb ? 1 + vel(stb->levo) + vel(stb->desno) : 0;

}

int zbir(Stablo stb) {

	return stb ? stb->broj + zbir(stb->levo) + zbir(stb->desno) : 0;

}

void pisi_kld(Stablo stb) {

	if (stb)
	{
		printf("%d ", stb->broj);
		pisi_kld(stb->levo);
		pisi_kld(stb->desno);
	}

}

void pisi_lkd(Stablo stb) {

	if (stb)
	{
		pisi_lkd(stb->levo);
		printf("%d ", stb->broj);
		pisi_lkd(stb->desno);
	}

}
void pisi_ldk(Stablo stb) {

	if (stb)
	{
		pisi_ldk(stb->levo);
		pisi_ldk(stb->desno);
		printf("%d ", stb->broj);
	}

}


void crtaj(Stablo stb, int nivo) {

	if (stb)
	{
		crtaj(stb->desno, nivo + 1);
		printf("%*s%d\n", 4 * nivo, "", stb->broj);
		crtaj(stb->levo, nivo + 1);
	}

}


int pojav(Stablo stb, int b) {

	return stb ? (stb->broj == b) + pojav(stb->levo, b) + pojav(stb->desno, b) : 0;

}

int min_u(Stablo stb) {

	return stb->levo ? min_u(stb->levo) : stb->broj;
}

int max_u(Stablo stb) {

	return stb->desno ? max_u(stb->desno) : stb->broj;
}

int min_n(Stablo stb) {

	int m = stb->broj, k;
	if (stb->levo)
	{
		k = min_n(stb->levo);
		if (k<m)
		{
			m = k;
		}
	}
	if (stb->desno)
	{
		k = min_n(stb->desno);
		if (k<m)
		{
			m = k;
		}

	}

	return m;
}


int max_n(Stablo stb) {

	int m = stb->broj, k;
	if (stb->levo)
	{
		k = max_n(stb->levo);
		if (k > m)
		{
			m = k;
		}
	}
	if (stb->desno)
	{
		k = max_n(stb->desno);
		if (k > m) {
			m = k;
		}
		
	}

	return m;
}

_Bool uredjeno(Stablo stb) {

	if (!stb)
	{
		return 1;
	}
	if (stb->levo && (!uredjeno(stb->levo) || max_u(stb->levo) > stb->broj))
	{
		return 0;
	}
	if (stb->desno && (!uredjeno(stb->desno) || min_u(stb->desno) < stb->broj));
	{
		return 0;
	}

	return 1;
}

Cvor* nadji_u(Stablo stb, int b) {

	if (!stb)
	{
		return NULL;
	}
	if (stb->broj==b)
	{
		return stb;
	}
	if (stb->broj > b)
	{
		return nadji_u(stb->levo, b);
	}
	else
	{
		return nadji_u(stb->desno, b);
	}

}

Cvor* nadji_n(Stablo stb, int b) {

	if (!stb)
	{
		return NULL;
	}
	if (stb->broj==b)
	{
		return stb;
	}
	Cvor* cvr = nadji_n(stb->levo, b);
	if (cvr)
	{
		return cvr;
	}
	return nadji_n(stb->desno, b);

}


Stablo dodaj_u(Stablo stb, int b) {
	if (!stb)
	{
		stb = malloc(sizeof(Cvor));
		stb->broj = b;
		stb->levo = stb->desno = NULL;
	}
	else if (stb->broj > b)
	{
		stb->levo = dodaj_u(stb->levo, b);
	}
	else if (stb->broj < b) {

		stb->desno = dodaj_u(stb->desno, b);
	}
	else if (rand() / (RAND_MAX + 1.) < 0.5)
	{
		stb->levo = dodaj_u(stb->levo, b);
	}
	else
	{
		stb->desno = dodaj_u(stb->desno, b);
	}

	return stb;
}


Stablo dodaj_n(Stablo stb, int b) {
	if (!stb)
	{
		stb = malloc(sizeof(Cvor));
		stb->broj = b;
		stb->levo = stb->desno = NULL;
	}
	else if (rand() / (RAND_MAX + 1.) < 0.5)
	{
		stb->levo = dodaj_u(stb->levo, b);
	}
	else
	{
		stb->desno = dodaj_u(stb->desno, b);
	}

	return stb;

}

Stablo citaj_u(int n) {
	Stablo stb = NULL;
	for (int i = 0; i < n; i++)
	{
		int b;
		scanf("%d", &b);
		dodaj_u(stb, b);

	}

	return stb;
}

Stablo citaj_n(int n) {

	Stablo stb = NULL;
	for (int i = 0; i < n; i++)
	{
		int b;
		scanf("%d", &b);
		dodaj_n(stb, b);

	}

	return stb;
}

Stablo brisi(Stablo stb) {
	if (stb)
	{
		stb->levo = brisi(stb->levo);
		stb->desno = brisi(stb->desno);
		free(stb);
		stb = NULL;
	}

	return stb;
}


Stablo izost_u(Stablo stb, int b){
	
	if (stb)
	{
		if (stb->broj > b)
		{
			stb->levo = izost_u(stb->levo, b);
		}
		else if (stb->broj < b)
		{
			stb->desno = izost_u(stb->desno, b);
		}
		else if (stb->levo)
		{
			int m = max_u(stb->levo);
			stb->broj = m;
			stb->levo = izost_u(stb->levo, m);
		}
		else if (stb->desno) {
			int m = min_u(stb->desno);
			stb->broj = m;
			stb->desno = izost_u(stb->desno, m);

		}
		else
		{
			free(stb);
			stb = NULL;
		}


	}


	return stb;
}


Stablo izost_n(Stablo stb, int b) {

	if (stb)
	{
		if (stb->broj==b)
		{
			if (stb->levo)
			{
				stb->broj = stb->levo->broj;
				stb->levo = izost_n(stb->levo, stb->broj);

			}
			else if (stb->desno)
			{
				stb->broj = stb->desno->broj;
				stb->desno = izost_n(stb->desno, stb->broj);

			}
			else
			{
				int v = vel(stb->levo);
				stb->levo = izost_n(stb->levo, b);
				if (v==vel(stb->levo)) //ako velicina levog ostane ista onda je taj broj u desnom podstablu
				{
					stb->desno = izost_n(stb->desno, b);
				}


			}


		}




	}

	return stb;
}

Stablo balans_u(Stablo stb) {

	if (stb)
	{
		int k = vel(stb->levo) - vel(stb->desno);
		for (; k > 1; k -= 2)
		{
			stb->desno = dodaj_u(stb->desno, stb->broj);
			stb->broj = max_u(stb->levo);
			stb->levo = izost_u(stb->levo, stb->broj);
		}
		for (; k < -1; k += 2)
		{
			stb->levo = dodaj_u(stb->levo, stb->broj);
			stb->broj = min_u(stb->desno);
			stb->desno = izost_u(stb->desno, stb->broj);

		}

		stb->levo = balans_u(stb->levo);
		stb->desno = balans_u(stb->desno);

	}


	return stb->desno;
}


Stablo balans_n(Stablo stb) {

	if (stb)
	{
		int k = vel(stb->levo) - vel(stb->desno);
		for (; k > 1; k -= 2)
		{
			stb->desno = dodaj_n(stb->desno, stb->broj);
			stb->broj = stb->levo->broj;
			stb->levo = izost_n(stb->levo, stb->broj);
		}
		for (; k < -1; k += 2)
		{
			stb->levo = dodaj_n(stb->levo, stb->broj);
			stb->broj = stb->desno->broj;
			stb->desno = izost_n(stb->desno, stb->broj);


		}

		stb->levo = balans_n(stb->levo);
		stb->desno = balans_n(stb->desno);


	}

	return stb;
}


_Bool moze(Stablo stb) {

	if (!uredjeno(stb))
	{
		printf("Nije uredjeno");
		return 0;
	}

	return 1;
}

Stablo radi(Stablo (*f)(Stablo, int), Stablo stb){

	int b;
	char zn;
	printf("Brojevi:  ");
	do
	{
		scanf("%d%c", &b, &zn);
		stb = (*f)(stb, b);


	} while (zn != '\n');


	return stb;
}



int main() {


	Stablo stb = stvori();
	_Bool kraj = 0;
	int n, broj;

	while (!kraj)
	{
		printf("\nDodavanje brojeva:   a) uredjeno b)neuredjeno\n"
			"Izostavljanje brojeva:    c)uredjeno d)neuredjeno\n"
			"Citanje stabla:           e)uredjeno f)neuredjeno\n"
			"Najmanji element:          g)uredjeno h)neuredjeno\n"
			"Najveci element:          i)uredjeno j)neuredjeno\n"
			"Pretrazivanje:          k)uredjeno l)neuredjeno\n"
			"Balansiranje:          m)uredjeno n)neuredjeno\n"
			"Pisanje stabla:  p)koren-levo-desno\n"
			"			      q)levo-koren-desno\n"
			"			      r)levo-desno-koren\n"
			"                 s)crtanje\n"
			"1.Velicina stabla    2.Zbir elemenata\n"
			"3.Broj pojavljivanja  4.Praznjenje stabla\n"
			"0.Kraj rada\n"
			"Vas izbor? ");
		char izbor[2]; scanf("%s", &izbor);
		switch (izbor[0])
		{

		case 'a': 
			if (moze(stb))
			{
				stb = radi(dodaj_u,stb);
			}
			break;
		case 'b':
			stb = radi(dodaj_n, stb);
			break;
		case 'c':
			if (moze(stb))
			{
				stb = radi(izost_u, stb);
			}
			break;
		case 'd':
			stb = radi(izost_n, stb);
		case 'e':
			printf("Duzina:   ");
			scanf("%d", &n);
			printf("Brojevi: ");
			brisi(stb);
			stb = citaj_u(n);
			break;

		case 'f':
			printf("Duzina:   ");
			scanf("%d", &n);
			printf("Brojevi: ");
			brisi(stb);
			stb = citaj_n(n);
			break;
		case 'g': case 'h': case 'i': case 'j':
			if (stb)
			{
				switch (izbor[0])
				{
				case 'g':
					if (moze(stb))
					{
						printf("min=  %d\n", min_u(stb));
						break;
					}
				case 'h':
					printf("min=  %d\n", min_n(stb));
					break;

				case 'i':
					if (moze(stb))
					{
						printf("max=  %d\n", max_u(stb));
						break;
					}
				case 'j':
					printf("max=  %d\n", max_n(stb));
					break;

				}

			}
			else
			{
				printf("Stablo je prazno\n");
				break;
			}
		case 'k': 
			if (moze(stb))
			{
				printf("Broj: ");
				scanf("%d", &broj);
				printf("Broj se %s nalazi u stablu\n", (nadji_u(stb, broj) != NULL ? "" : "NE"));

			}
			break;
		case 'l':
			printf("Broj: ");
			scanf("%d", &broj);
			printf("Broj se %s nalazi u stablu\n", (nadji_n(stb, broj) != NULL ? "" : "NE"));
			break;
		case 'm':
			if (moze(stb))
			{
				stb = balans_u(stb);
			}
			break;
		case 'n':
			stb = balans_n(stb);
			break;

		case 'p':
			printf("Stablo:   ");
			pisi_kld(stb);
			putchar('\n');
			break;
		case 'q':
			printf("Stablo:   ");
			pisi_lkd(stb);
			putchar('\n');
			break;
		case 'r':
			printf("Stablo:   ");
			pisi_ldk(stb);
			putchar('\n');
			break;
		case 's':
			crtaj(stb, 0);
			break;


		case '1':
			printf("Vel=  %d\n",vel(stb));
			break;
		case '2':
			printf("Zbir=  %d\n", zbir(stb));
			break;
		case '3':
			printf("Broj: \n");
			scanf("%d", &broj);
			printf("Broj se pojavljuje %d puta", pojav(stb, broj));
			break;
		
		case '4':
			stb = brisi(stb);
			break;

		case '0':
			kraj = 1;
			break;

		default:
			printf("Nedozvoljen izbor\a\n");
			break;
		}


	}








	return 0;
}