/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.
*/

void mark(vector<vector<int> >& image, int row, int column, int startcolor, int newcolor){
        
    if( row<0 || row>=image.size() || column<0 || column>=image[0].size() ){
        return;
    }
    
    if( image[row][column]!=startcolor ){
        return;
    }
    
    if( image[row][column]==newcolor ){
        return;
    }
    
    image[row][column] = newcolor;        
    
    mark( image, row-1, column, startcolor, newcolor );
    mark( image, row, column+1, startcolor, newcolor );
    mark( image, row+1, column, startcolor, newcolor );
    mark( image, row, column-1, startcolor, newcolor );            
    
    return;
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    
    mark( image, sr, sc, image[sr][sc], newColor );
    
    return image;        
}