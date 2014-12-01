#ifndef STATICAREA_H
#define STATICAREA_H

#include <string>
#include <vector>
#include <unordered_map>

#include "TileSetLoader.h"
#include "ZoneSetLoader.h"
#include "ZoneLinker.h"

class StaticArea
{
public:
    StaticArea(std::string const& key, std::string const& scenarioDir);
    virtual ~StaticArea();

    typedef std::unordered_map<std::string,TileSetLoader::TileSet> TileSetMapping;

    std::string getKey() const;
    const ZoneSetLoader::ZoneSet& getZoneSet() const;
    TileSetLoader::TileSet getZone(std::string const& key); /** @todo usefull without const ? */
    TileSetLoader::TileSet getZone(Position const& pos); /** @todo usefull without const ? */
    const TileSetLoader::TileSet& getZone(std::string const& key) const;
    const TileSetLoader::TileSet& getZone(Position const& pos) const;
    const ZoneLinker *getLinker() const;

protected:
private:
    std::string m_key;
    ZoneSetLoader::ZoneSet m_zoneSet;
    StaticArea::TileSetMapping m_loadedTileSets;
    ZoneLinker* m_zoneLinker = NULL;

    void m_loadSet(std::string const& scenarioDir);
};

#endif // STATICAREA_H
