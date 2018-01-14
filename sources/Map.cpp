#ifndef MAP_H
#define MAP_H

#include <vector>
#include "TextureManager.cpp"
#include "../tileset/level0.cpp"

#define DF_TileSize 20

class Map
{
private:
    SDL_Rect src, dst;
    std::vector<SDL_Texture*> textures;
    int minimumTreadTile = 1; // If a tile is minus than this value, we can't step in.
    int map[][DF_mapCols];

public:
    Map(std::vector<std::string> filenames)
    {
        int size = filenames.size();

        for(int i = 0; i<size; ++i)
            textures.push_back(TextureManager::LoadTexture(filenames[i]));

        loadMap(cargaMapa());

        src.x = src.y = 0; // Soruce on (0,0);
        src.x = src.y = DF_TileSize; // Soruce on (0,0);
        dst.x = dst.y = 0;
    }

    ~Map()
    {

    }

    /*inline void loadMap(const unsigned char *arr[DF_mapCols]) const 
    {
        for(int r = 0; r < DF_mapRows; ++r)
        {
            for(int c = 0; c < DF_mapCols; ++c)
                map[r][c] = arr[r][c];
        }
    }*/

    std::vector<std::vector<unsigned char>> cargaMapa()
    {
        std::vector<unsigned char> v;
        std::vector<std::vector<unsigned char>> ret;

        for(int i = 0; i < 12; ++i)
            v.push_back(0);

        v.push_back(1);

        for(int i = 0; i < 6; ++i)
            v.push_back(2);

        v.push_back(1);

        for(int i = 0; i < 12; ++i)
            v.push_back(0);

        for(int i = 0; i < 18; ++i)
            ret.push_back(v);

        for(int i = 0; i < 18; ++i)
        {
            for(int j = 0; j < 32; ++j)
                std::cout << (int)ret[i][j] << " ";

            std::cout << std::endl;
        }

        return ret;
    }

    inline void loadMap(std::vector<std::vector<unsigned char>> v)
    {
        for(int r = 0; r < v.size(); ++r)
        {
            for(int c = 0; c < v[r].size(); ++c)
                map[r][c] = (int)v[r][c];
        }
    }

    inline void drawMap()
    {
        std::cout << "kk";
        int type = -1;
        for(int r = 0; r < DF_mapRows; ++r)
        {
            for(int c = 0; c < DF_mapCols; ++c)
            {
                type = map[r][c];
                dst.x = c * DF_TileSize; // Move DF_TileSize px.
                dst.y = r * DF_TileSize; // Move DF_TileSize px.

                TextureManager::Draw(textures[type], src, dst);
            }
        }
    }
};

#endif