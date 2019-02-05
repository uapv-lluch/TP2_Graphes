/**
 * n = nombre de sommet, constante du programme
 * c = Matrice correspondante au graphe, -1 est la valeur par défaut pour les arcs inexistants. 
 * C = vecteur dont l'indice correspond au sommet concerné de booléens. Equivalent à visites pour Ford et Fulkerson
 * père = vecteur dont l'indice correspond au sommet concerné et la valeur au sommet predecesseur
 * d = vecteur dont l'indice correspond au sommet concerné et la distance necessaire pour y parvenir
 * 
 * C = {0}
 * d(0) = 0, Initialiser à -1 les autres cases
 * Initaliser père à 0
 * j = 1
 * Pour l allant de 1 (premier sommet non visité) < n:
 *      pour les sommets i non présent dans C && connecté à j:
 *          si la distance est plus courte que celle présente dans d:
 *              on met à jour d(i)
 *              on met à jour p(i) avec j
 *      
 *      j = minimum des distances d pour i not in C
 *      C += i 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 