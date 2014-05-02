#include "json.hpp"
#include "os.hpp"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

namespace json {

QJsonObject read(QString const &fname)
{
    auto data = os::read_file(fname);
    auto doc = QJsonDocument::fromJson(data);
    return doc.object();
}

ssize_t write(QJsonObject const &src, QString const &fname)
{
    QJsonDocument doc(src);
    return os::write_file(fname, doc.toJson());
}

ssize_t write(QVariantMap const &src, QString const &fname)
{
    return write(QJsonObject::fromVariantMap(src), fname);
}

}