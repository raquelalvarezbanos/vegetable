#ifndef IMAINWINDOWVIEW_H
#define IMAINWINDOWVIEW_H

#include <string>

class IMainWindowView
{
public:
    ~IMainWindowView(){};

    // Returns current year
    virtual std::string currentYear() const = 0;
    // Sets current year
    virtual void setCurrentYear(const std::string &year) = 0;
    // Prompt
    virtual void showError(const std::string &prompt,
                           const std::string &title) = 0;
};

#endif // IMAINWINDOWVIEW_H
