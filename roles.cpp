#include "roles.h"

Roles::Roles() : _type(Roles::Type::OPERATOR)
{

}

Roles::Roles(Roles::Type type) : _type(type)
{

}

QString Roles::roleName(const Roles &role)
{
    return ROLE_NAMES[role.type()];
}

Roles Roles::stringToRole(const QString &roleName)
{
    int index = ROLE_NAMES.indexOf(roleName);
    if (index == -1)
        return {Roles::Type::OPERATOR};

    return {static_cast<Roles::Type>(index)};
}

void Roles::setType(Roles::Type newType)
{
    _type = newType;
}

Roles::Type Roles::type() const
{
    return _type;
}
