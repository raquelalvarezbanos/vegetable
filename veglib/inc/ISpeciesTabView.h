#ifndef ISPECIESTABVIEW_H
#define ISPECIESTABVIEW_H

#include <set>
#include <string>

class ISpeciesTabView {

public:
    virtual ~ISpeciesTabView(){};

    virtual std::string askUserNewRow(const std::string &title,
                                          const std::string &prompt,
                                          const std::string &defaultValue) = 0;

    virtual void appendRow(const std::string &rowName) = 0;

    virtual void removeRows()  = 0;
};

#endif // ISPECIESTABVIEW_H

