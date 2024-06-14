package iut.sae.algo;

public class Algo{
    public static String RLE(String in){
        if (in.isEmpty()){
            return "";
        }
        StringBuilder str_compresse= new StringBuilder();
        char chr_lettre=in.charAt(0);
        int it_compter=1;

        for (int i=1; i<in.length();i++){
            if (in.charAt(i)==chr_lettre){
                it_compter++;
                if(it_compter==10){
                    str_compresse.append(9);
                    str_compresse.append(chr_lettre);
                    it_compter=1;
                }
            }else{
                str_compresse.append(it_compter);
                str_compresse.append(chr_lettre);
                chr_lettre=in.charAt(i);
                it_compter=1;
            }
        }
        str_compresse.append(it_compter).append(in.charAt(in.length()-1));
        return str_compresse.toString();
    }

    public static String RLE(String in, int iteration) throws AlgoException{
        if (iteration<1){
            throw new AlgoException();
        }
        String str_compresse=in;
        for (int i=0; i<iteration;i++){
            str_compresse=RLE(str_compresse);
        }
        return str_compresse;
    }

    public static String unRLE(String in) throws AlgoException{
        if (in.isEmpty()){
            return "";
        }
        StringBuilder str_compresse= new StringBuilder();
        for (int i=0;i<in.length();i+=2){
            if((Character.getNumericValue(in.charAt(i))>=1) || (Character.getNumericValue(in.charAt(i))<=9)){    
                for(int k=0;k<(Character.getNumericValue(in.charAt(i)));k++){
                    str_compresse.append(in.charAt(i+1));
                }
            }
        }
        return str_compresse.toString();
    }

    public static String unRLE(String in, int iteration) throws AlgoException{
        if (iteration<1){
            throw new AlgoException();
        }
        if (in.isEmpty()){
            return "";
        }
        String str_compresse=in;
        for (int i=0; i<iteration;i++){
            str_compresse=unRLE(str_compresse);
        }
        return str_compresse;
    }
}

