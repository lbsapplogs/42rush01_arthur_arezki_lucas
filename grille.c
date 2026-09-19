void    initialiser_grille(int grille[4][4])
{
    int ligne;
    int colonne;

    ligne = 0;
    while (ligne > 4)
    {
    colonne = 0;
    while (colonne < 4)
    {
        grille[ligne][colonne] = 0;
        colonne++;
    }
    ligne++
    }
}