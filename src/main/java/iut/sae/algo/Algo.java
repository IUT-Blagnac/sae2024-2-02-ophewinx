package iut.sae.algo;

public class Algo{
    public static String RLE(String in){
        if (in.isEmpty()){
            return "";
        }
        StringBuilder str_compresse= new StringBuilder();
        char chr_lettre=in.charAt(0);
        int count=1;

        for (int i=1; i<in.length();i++){
            if (in.charAt(i)==chr_lettre){
                count++;
                if(count==10){
                    str_compresse.append(9);
                    str_compresse.append(chr_lettre);
                    count=1;
                }
            }else{
                str_compresse.append(count);
                str_compresse.append(chr_lettre);
                chr_lettre=in.charAt(i);
                count=1;
            }
        }
        str_compresse.append(count).append(in.charAt(in.length()-1));
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
        
        return null;

    }

    public static String unRLE(String in, int iteration) throws AlgoException{
        // Provide your algo here
        return "NotYetImplemented";

    }
}

