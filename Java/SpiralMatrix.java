import java.util.List;
import java.util.ArrayList;
public class SpiralMatrix {

        public List<Integer> spiralOrder(int[][] matrix) {
            
            /**declaring a list to return output spiral in*/
            List<Integer> output = new ArrayList();
            
             if(matrix == null || matrix.length == 0 ){
                  return output;
             }
            
            
            /*left column*/
            int left_c = 0;
            /**top row*/
            int top_r = 0;
            /**right column*/
            int right_c = matrix[0].length -1 ;
            /**bottom row*/
            int bottom = matrix.length - 1;
            
            /**size of the matrix given by the length of matrix and length of each column*/
            int m_size = matrix.length * matrix[0].length; //esentially like mxn
            
            /**while loop to track that the number of items in output list include all elements in matrix*/
            while(output.size() < m_size){
                
                /**top row, left to right*/
                for (int col = left_c; col <= right_c && output.size() < m_size; col++){
                    output.add(matrix[top_r][col]);
                }
                /**increment top row reflect next row below it*/
                top_r++;
                /**right column, top down*/
                for(int row = top_r; row <= bottom && output.size() < m_size; row++){
                    output.add(matrix[row][right_c]);
                }
                /**decrease right value to get closer to the left*/
                right_c--;
               /**bottom column, right to left*/
                for(int l_outer = right_c; l_outer >= left_c && output.size() < m_size; l_outer--){
                    output.add(matrix[bottom][l_outer]);
                }
                /**go a level above the bottom by decreasing its value*/
                bottom--;
                
                /**from the bottom,add left most column*/
                for(int upward = bottom; upward >= top_r && output.size() < m_size; upward--){
                    output.add(matrix[upward][left_c]);
                    
                    System.out.println("upward value, left value" + upward +" "+ left_c);
                }
                /**move inward from the left toward the right*/
                left_c++;
                
                /**the while loop will continue until all elements in matrix have been added to output list*/
               
            }
            //return output array
            return output; 
        }

        public static void main(String[] args) {
            SpiralMatrix spiral = new SpiralMatrix();

            int[][] matrix = new int[3][3];
            int n = 3;
            int increase = 1;

            for(int i=0; i <n; i++){
                for(int j=0; j<n; j++){
                    matrix[i][j] = increase;
                    increase++; 
                }
            }
            /***[[1,2,3],[4,5,6],[7,8,9]]; */
            System.out.println(" Spiral Matrix result"+ spiral.spiralOrder(matrix));
        }
    }
    
