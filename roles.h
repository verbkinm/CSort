#pragma once

#include <QStringList>

inline const QStringList ROLE_NAMES = {"OPERATOR", "TECHNIACIAN", "ENGINEER"};

class Roles
{
public:
    enum Type
    {
        OPERATOR,
        TECHNIACIAN,
        ENGINEER
    };

    Roles();
    Roles(Roles::Type type);

    Roles::Type type() const;
    void setType(Roles::Type newType);

    static QString roleName(const Roles &role);
    static Roles stringToRole(const QString &roleName);

private:
    Roles::Type _type;
};

