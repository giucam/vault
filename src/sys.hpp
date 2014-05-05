#ifndef _CUTES_SYS_HPP_
#define _CUTES_SYS_HPP_

#include "util.hpp"

namespace sys {

QStringList command_line_options
(QVariantMap const &options
 , string_map_type const &short_options = string_map_type()
 , string_map_type const &long_options = string_map_type()
 , QMap<QString, bool> const &options_has_param = QMap<QString, bool>());

class GetOpt
{
public:
    virtual ~GetOpt() {}
    virtual QString value(QString const &name) const =0;
    virtual bool isSet(QString const &name) const =0;
    virtual QStringList arguments() const =0;
};

std::unique_ptr<GetOpt> getopt(QVariantMap const &);

}

#endif // _CUTES_SYS_HPP_
