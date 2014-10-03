#pragma once

#include <QObject>

namespace GammaRay {
namespace Util {

    inline QString displayString(const QObject *object)
    {
      if (!object) {
        return "QObject(0x0)";
      }
      if (object->objectName().isEmpty()) {
        return QString::fromLatin1("%1").arg(object->metaObject()->className());
      }
      return object->objectName();
    }


    inline bool descendantOf(const QObject *ascendant, const QObject *obj)
    {
      QObject *parent = obj->parent();
      if (!parent) {
        return false;
      }
      if (parent == ascendant) {
        return true;
      }
      return descendantOf(ascendant, parent);
    }


}
}