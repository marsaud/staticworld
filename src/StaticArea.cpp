#include "StaticArea.h"

StaticArea::StaticArea(std::string const& key, std::string const& scenarioDir)
{
    m_zoneLinker = new ZoneLinker(scenarioDir + "/" + key + "/" + ZoneLinker::ZONE_LINK_FILE);
    m_loadSet(scenarioDir + "/" + key);
    m_key = key;
}

StaticArea::~StaticArea()
{
    delete m_zoneLinker;
    m_loadedTileSets.clear();
    m_zoneSet.clear();
}

void StaticArea::m_loadSet(std::string const& areaDir)
{
    m_zoneSet.clear();

    ZoneSetLoader* zLoader = new ZoneSetLoader;
    zLoader->load(areaDir + "/" + ZoneSetLoader::ZONESET_FILE, m_zoneSet);
    delete zLoader;

    TileSetLoader* tLoader = new TileSetLoader;
    for(ZoneSetLoader::ZoneSet::const_iterator yit = m_zoneSet.cbegin(); m_zoneSet.cend() != yit; ++yit)
    {
        for(ZoneSetLoader::ZoneSetLine::const_iterator xit = yit->cbegin(); yit->cend() != xit; ++xit)
        {
            TileSetLoader::TileSet tileSet;
            tLoader->load(areaDir + "/" + *xit + "." + TileSetLoader::TILEMAP_FILE_EXT, tileSet);
            m_loadedTileSets[*xit] = tileSet;
        }
    }
    delete tLoader;
}

const ZoneSetLoader::ZoneSet& StaticArea::getZoneSet() const
{
    return m_zoneSet;
}

TileSetLoader::TileSet StaticArea::getZone(std::string const& key)
{
    return m_loadedTileSets.at(key);
}

TileSetLoader::TileSet StaticArea::getZone(Position const& pos)
{
    return getZone(m_zoneSet[pos.y][pos.x]);
}

const TileSetLoader::TileSet& StaticArea::getZone(std::string const& key) const
{
    return m_loadedTileSets.at(key);
}

const TileSetLoader::TileSet& StaticArea::getZone(Position const& pos) const
{
    return getZone(m_zoneSet[pos.y][pos.x]);
}

const ZoneLinker* StaticArea::getLinker() const
{
    return m_zoneLinker;
}

std::string StaticArea::getKey() const
{
    return m_key;
}
