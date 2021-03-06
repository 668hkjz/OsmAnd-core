/**
* @file
*
* @section LICENSE
*
* OsmAnd - Android navigation software based on OSM maps.
* Copyright (C) 2010-2013  OsmAnd Authors listed in AUTHORS file
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.

* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __OBF_ADDRESS_SECTION_INFO_H_
#define __OBF_ADDRESS_SECTION_INFO_H_

#include <cstdint>
#include <memory>

#include <QList>

#include <OsmAndCore.h>
#include <OsmAndCore/CommonTypes.h>
#include <OsmAndCore/Data/ObfSectionInfo.h>

namespace OsmAnd {

    class ObfAddressSectionReader_P;
    class ObfReader_P;

    STRONG_ENUM(ObfAddressBlockType)
    {
        CitiesOrTowns = 1,
        Villages = 3,
        Postcodes = 2,
    };
#ifndef SWIG
    inline uint qHash(ObfAddressBlockType value, uint seed = 0) Q_DECL_NOTHROW
    {
        return ::qHash(static_cast<int>(value), seed);
    }
#endif

    class ObfAddressBlocksSectionInfo;

    class OSMAND_CORE_API ObfAddressSectionInfo : public ObfSectionInfo
    {
        Q_DISABLE_COPY(ObfAddressSectionInfo)
    private:
    protected:
        ObfAddressSectionInfo(const std::weak_ptr<ObfInfo>& owner);

        //NOTE:?
        QString _latinName;

        QList< std::shared_ptr<const ObfAddressBlocksSectionInfo> > _addressBlocksSections;
    public:
        virtual ~ObfAddressSectionInfo();

        const QList< std::shared_ptr<const ObfAddressBlocksSectionInfo> >& addressBlocksSections;

        friend class OsmAnd::ObfAddressSectionReader_P;
        friend class OsmAnd::ObfReader_P;
    };

    class OSMAND_CORE_API ObfAddressBlocksSectionInfo : public ObfSectionInfo
    {
        Q_DISABLE_COPY(ObfAddressBlocksSectionInfo)
    private:
    protected:
        ObfAddressBlocksSectionInfo(const std::shared_ptr<const ObfAddressSectionInfo>& addressSection, const std::weak_ptr<ObfInfo>& owner);

        ObfAddressBlockType _type;
    public:
        virtual ~ObfAddressBlocksSectionInfo();

        const ObfAddressBlockType& type;

        friend class OsmAnd::ObfAddressSectionReader_P;
        friend class OsmAnd::ObfReader_P;
    };

} // namespace OsmAnd

#endif // __OBF_ADDRESS_SECTION_INFO_H_
