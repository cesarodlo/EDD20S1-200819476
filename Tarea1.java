import java.util.*;
class Tarea1{
    public static void main (String[]args){
        Scanner in=new Scanner(System.in);
                
        System.out.println("Ingresar tamaño de la matriz ");
        int t=in.nextInt();
        int matriz[][]=new int[t][t];
        if(t>0){
            //llenado de linea superior e inferior de la matriz
            for(int i=0;i<t;i++){
                matriz[0][i]=1;
                matriz[t-1][i]=1;
            }
            //llenado de laterales de la matriz
            for(int k=0;k<t-1;k++){
                matriz[k][0]=1;
                matriz[k][t-1]=1;
            }
        }
        //imprimiendo la matriz
        for(int i=0;i<t;i++){
            for(int j=0;j<t;j++){
                System.out.print(matriz[i][j]);
            }
            System.out.println(" ");
        }
            
    }
}