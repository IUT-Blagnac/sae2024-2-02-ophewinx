import time


class simplicite:
    def RLE(en):
        nouvelle_str = "" # ajoute nouvelle chaine
        while en: # tant que la chaine n'est pas vide
            i = 0 # initialise compteur a 0
        while i < len(en) and en[i] == en[0] and i < 9: # continue tant que les caracteres sont similaires et tant que depasse pas de la len de en et de 9
            i += 1 
        nouvelle_str += str(i)+en[0] # ajoute le nombre de repetition et le premier caractere
        en = en[i:] # suprime de la chaine de base bout deja analysé 
        return nouvelle_str
      
    def RLER(en, iteration):
        nouvelle_str = "" # ajoute nouvelle chaine
        while en: # tant que la chaine n'est pas vide
            i = 0 # initialise compteur a 0
        while i < len(en) and en[i] == en[0] and i < 9: # continue tant que les caracteres sont similaires et tant que depasse pas de la len de en et de 9
            i += 1 
        nouvelle_str += str(i)+en[0] # ajoute le nombre de repetition et le premier caractere
        en = en[i:] # suprime de la chaine de base bout deja analysé 
        if iteration == 1:
            return nouvelle_str
        return simplicite.RLER(nouvelle_str, iteration-1) # rappelle la fonction avec la nouvelle chaine 

    def unRLE(en):
        nouvelle_str = "" # nouvelle chaine 
        while en: # tant que la chaine n'est pas vide
            nouvelle_str += str(int(en[0])*en[1]) # ajoute le caractere en pos 1 * le nbr en pos 0
            en = en[2:] # supprime ce bout de la chaine
        return nouvelle_str # retourne la nouvelle chaine

    def unRLER(en, iteration):
        nouvelle_str = "" # nouvelle chaine
        while en: # tant que la chaine n'est pas vide
            nouvelle_str += str(int(en[0])*en[1]) # ajoute le caractere en pos 1 * le nbr en pos 0
            en = en[2:] # supprime ce bout de la chaine
        if iteration == 1: # si une seule iteration retourne le resultat
            return nouvelle_str 
        return simplicite.unRLER(nouvelle_str, iteration-1) # rappelle la fonction avec la nouvelle chaine et iteration-1
    
    @staticmethod
    def main():
        import sys

        if len(sys.argv) > 1:
            in_string = sys.argv[1]
        else:
            in_string = input("Chaine à transformer : ")

        print("Entrée : " + in_string)

        start_time = time.perf_counter()
        output = simplicite.unRLE(in_string)  
        end_time = time.perf_counter()

        print("Sortie : " + output)

        duration_seconds = end_time - start_time
        duration_millis = duration_seconds * 1000.0

        print(f"Temps d'exécution : {duration_seconds:.6f} s ({duration_millis:.3f} ms)")

if __name__ == "__main__":
    simplicite.main()