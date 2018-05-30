/**
 * @brief global GUI window interface
 * @details This file contains the interface that decides what a GUI window is and should contain.
 * This GUI interface used OpenCV's own Hi-GUI module. This is the most optimal. Other libraries might provide some slower response
 * time.
 * @file gui.hpp
 * @author Arsalan Anwari
 * @date 2018-05-19
 */

#ifndef GUI_HPP
#define GUI_HPP

#include "opencv2/highgui.hpp"
#include "window.hpp"

/**
 * @brief Enum list of states the GUI could be in
 */
enum class states { open, closed, hidden };

namespace lucidy {

/**
 * @brief GUI window interface
 *
 */
class Gui : public Window {
  protected:
    states state;                             /// current state of GUI process
    settings::WIN::GUI::data window_settings; /// configurable settings of GUI window
  public:
    /**
     * @brief This function is used to initialize the openCV window manager
     * @details A new instance of the window manager has to be made with custom user settings.
     * This is due to the implementation method of openCV with multple windows.
     * Each window get's specified a name and can be retrieved using this name in a map.
     */
    void init() override;

    /**
     * @brief This function is used to (re)open the current window
     *
     */
    void open() override;

    /**
     * @brief This function is used to close the current window and delete it from the list
     *
     */
    void close() override;

    /**
     * @brief This function is used to only hide the window temporary until it is opend again
     *
     */
    void hide();

    /**
     * @brief This function returns wether the window is currently open
     *
     * @return true : window is open
     * @return false : window is hidden or closed
     */
    bool isOpen();

    /**
     * @brief This function is used to return the current state of the gui window manager
     *
     * @return states
     */
    states getState();

    /**
     * @brief This function is used to return the current user settings that are being used
     *
     * @return settings::WIN::GUI::data&
     */
    settings::WIN::GUI::data &getSettings();
};

} // namespace lucidy

#endif // GUI_HPP
