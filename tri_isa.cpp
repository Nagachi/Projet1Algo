/**
 * @file tri_isa.cpp
 * @author
 * @date
 * @brief
**/
#include <iostream>  // cout, cin
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time(), clock_t, clock(), CLOCKS_PER_SEC
#include <cassert>   // assert()
#include <climits>   // UINT_MAX
#include <cfloat>    // DBL_MAX
using namespace std;

//--------------------------------------------------------------------
// Éléments de mesure de performance

/**
 * @var UT
 * @brief variable de comptage des unités de temps
**/
unsigned int UT = 0;

//--------------------------------------------------------------------

/*
*********************
*****  Partie 1 *****
*********************
*/

// Définition du type tableau TabEntier
const unsigned int N = 10;
typedef int TabEntier[N];

// Procédure permettant de remplir un tableau avec les entiers de 0 à N-1 (croissant)
void remplir_croissant(TabEntier & T)
{
	unsigned int i;
	for(i=0; i<N; ++i)
	{
		T[i] = i;
	}
}

// Procédure permettant de remplir un tableau avec les entiers de N-1 à 0 (décroissant)
void remplir_decroissant(TabEntier & T)
{
	unsigned int i;
	for(i=0; i<N; ++i)
	{
		T[i] = N - i - 1;
	}
}

// Procédure permettant de permuter deux éléments d'un tableau T aux indices i et j.
void permuter(TabEntier &T, unsigned int i, unsigned int j)
{
	int tmp;

	tmp = T[i];
	T[i] = T[j];
	T[j] = tmp;
}

// Procédure permettant d'effectuer k permutation avec des indices aléatoires.
void permuter_rand(TabEntier &T, unsigned int k)
{
    assert(N != 0); // Pré-condition : la taille du tableau doit être différente de 0 pour éviter une division par 0 lors de l'affectation des valeurs a et b ci-dessous

	int a,b;
	unsigned int i;

        for (i = 0; i < k; ++i)
        {
            a = rand()%(N);       // valeur recherchée : aléatoire entre 0 et N
            b = rand()%(N);       // valeur recherchée : aléatoire entre 0 et N
            permuter(T, a, b);
        }
}

// Fonction permettant de savoir si un tableau est trié dans l'ordre croissant.
bool is_croissant(TabEntier T)
{
	bool test = true;
	unsigned int i;

	for (i = 0; i < N-1; ++i)
	{
		if (T[i] > T[i+1])
		{
			test = false;
		}
	}

	return test;
}

// Procédure permettant d'afficher un tableau sur la sortie standard
void afficher_tab(TabEntier T)
{
	unsigned int i;
	for (i = 0; i < N; ++i)
	{
		cout << T[i] << "|";
	}
	cout << endl;
}

/*
*********************
*****  Partie 2 *****
*********************
*/

//--------------------------------------------------------------------
// Procédure de tri par selection
void TriSelection (TabEntier & T)
{
	unsigned i, j, min;

	for (i = 0; i < N; ++i)
	{
		min = i;

		for (j = i+1; j < N; ++j)
		{
			if(T[j] < T[min])
			{
				min = j;
			}
		}

		if(min != i)
		{
			permuter(T, min, i);
		}
	}
}

//--------------------------------------------------------------------
/**
 * @brief Procédure de tri par insertion
 *
 * @param Tableau d'entiers T
 *
 * @b Role : Tri un tableau d'entiers par ordre croissant
 *
 * @b Cadre : pas de restriction
 *
 * @pre -
 * @post Soit Td = Tableau de début et Tf = Tableau de fin. On a (|Td| = |Tf|) et ( pour tout i dans 0..|T|-1, T[i] <= T[i+1] ) et ( tous les éléments présents dans Td sont présents dans Tf )
 *
 *@test
 * |       Entrée      |       Sortie      | Justification | Résultat |
 * |-------------------|-------------------|---------------|----------|
 * |T = [1,2,4,3,0]    |T = [0,1,2,3,4]    |VOIR PLUS TARD | passe    |
 * |T = [0,1,2,3,4]    |T = [0,1,2,3,4]    |VOIR PLUS TARD | passe    |
 * |T = [4,3,2,1,0]    |T = [0,1,2,3,4]    |VOIR PLUS TARD | passe    |
 * |T = []             |T = []             |0 itération    | passe    |
**/
void TriInsertion(TabEntier & T)
{
	unsigned int i, j;

	for (i = 1; i < N; ++i)
	{
		j = i;

		while((j > 0) && (T[j] < T[j-1]))
		{
			permuter(T, j, j-1);
			j--;
		}
	}
    /*
    // Post-conditions

    bool post_cond_insert = ( N == taille_tab(T) ); // 1ère Post-condition
    unsigned int i = 0;

    // 2ème post-condition
    while ( ( i < N ) && post_cond_insert)
    {
        if (T[i] > T[i+1])
        {
            post_cond_insert = false;
        }
        i++;
    }

    // 3ème post-condition à faire

    assert(post_cond_insert);
    */


}
//--------------------------------------------------------------------
/**
 * @brief Procédure de tri aléatoire
 *
 * @param Tableau d'entiers T
 *
 * @b Role : Tri un tableau d'entiers par ordre croissant
 *
 * @b Cadre : pas de restriction
 *
 * @pre -
 * @post Soit Td = Tableau de début et Tf = Tableau de fin. On a (|Td| = |Tf|) et ( pour tout i dans 0..|T|-1, T[i] <= T[i+1] ) et ( tous les éléments présents dans Td sont présents dans Tf )
 *
 *@test
 * |       Entrée      |       Sortie      | Justification | Résultat |
 * |-------------------|-------------------|---------------|----------|
 * |T = [1,2,4,3,0]    |T = [0,1,2,3,4]    |VOIR PLUS TARD | passe    |
 * |T = [0,1,2,3,4]    |T = [0,1,2,3,4]    |VOIR PLUS TARD | passe    |
 * |T = [4,3,2,1,0]    |T = [0,1,2,3,4]    |VOIR PLUS TARD | passe    |
 * |T = []             |T = []             |VOIR PLUS TARD | échec    |
**/
void TriAleatoire(TabEntier & T)
{
	bool estTrie;
	estTrie = is_croissant(T);

	while(estTrie == false)
	{
		permuter_rand(T, 1);
		estTrie = is_croissant(T);
	}
    /*
    // Post-conditions

    bool post_cond_alea = ( N == taille_tab(T) ); // 1ère Post-condition
    unsigned int i = 0;

    // 2ème post-condition
    while ( ( i < N ) && post_cond_alea)
    {
        if (T[i] > T[i+1])
        {
            post_cond_alea = false;
        }
        i++;
    }

    // 3ème post-condition à faire

    assert(post_cond_alea);
    */
}

//--------------------------------------------------------------------
/**
 * @brief fonction principale
 *
 * @b Role : -
 *
 * @b Cadre : -
 *
 * @pre -
 * @post -
**/

int main()
{
	srand((int)time(0));   // initialisation du tirage aléatoire
	TabEntier T;

	//remplir_croissant(T);
	remplir_decroissant(T);
	//permuter_rand(T, 100);
	afficher_tab(T);
	//TriSelection(T);
	//TriInsertion(T);
	TriAleatoire(T);
	afficher_tab(T);
	//cout << is_croissant(T) << endl;


	return 0;
}
