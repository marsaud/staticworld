#ifndef TILESETLOADER_H
#define TILESETLOADER_H

#include <string>
#include <vector>
#include <fstream>

class TileSetLoader
{
public:
    TileSetLoader();
    virtual ~TileSetLoader();

    enum Tile
    {
        TILE_NONE, TILE_CAVE, TILE_DIRT, TILE_FOREST, TILE_GRASS, TILE_HILL, TILE_MOUNT, TILE_WATER, TILE_PARTY, TILE_LIST_SIZE
    };

    typedef std::vector<TileSetLoader::Tile> TileSetLine;
    typedef std::vector<TileSetLoader::TileSetLine> TileSet;

    static const std::string TILEMAP_FILE_EXT;

    bool load(std::string const& tileMapPath, TileSetLoader::TileSet & tileSet) const;
protected:
private:
    enum DataFileChar
    {
        CAVE = 'v', DIRT = 'd', FOREST = 'f', GRASS = 'g', HILL = 'h', MOUNT = 'm', WATER = 'w', LINE_BREAK = '\n'
    };
};

#endif // TILESETLOADER_H
