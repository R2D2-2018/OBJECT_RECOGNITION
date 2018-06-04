/**
 * @brief globalized window interface
 * @details This file contains the interface that specifies what kind of displays (graphical, text, etc)
 * are considered a window with the required functions. Each window should be able to opened, closed and be initialized.
 * @file window.hpp
 * @author Arsalan
 * @date 2018-05-19
 */

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "external/settings.hpp"
namespace lucidy {

/**
 * @brief Window interace
 */
class Window {
  protected:
    /// This is used distinguis multiple windows that can be opend simontaniously
    const char *name;

  public:
    /**
     * @brief function that should be used to initialize a window
     *
     */
    virtual void init() = 0;

    /**
     * @brief function that should be used to open a window
     *
     */
    virtual void open() = 0;

    /**
     * @brief function that should be used to close a window
     *
     */
    virtual void close() = 0;
};

} // namespace lucidy

#endif // WINDOW_HPP
