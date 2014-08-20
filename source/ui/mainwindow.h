#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QSettings>
#include <QModelIndex>
#include <QStringList>

#include "mpvhandler.h"
#include "playlistmanager.h"
#include "lightdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QSettings *settings, QWidget *parent = 0);
    ~MainWindow();

public slots:
    void HandleError(QString err);                  // triggered by any aspect to display an error message

protected:
    virtual void dragEnterEvent(QDragEnterEvent *event);
    virtual void dropEvent(QDropEvent *event);      // drop file into

    inline void SetPlaybackControls(bool enable);   // macro to enable/disable playback controls

private slots:
    QString FormatTime(int time);                   // format the time the way we want to display it
    void SetTime(int time);                         // triggered by mpv, updates time labels and seekbar
    void SetPlayState(Mpv::PlayState state);        // triggered by mpv, updates controls based on changes of playstate
    void Seek(int position);                        // converts seekbar location to mpv->Seek command
    void PlayPause();                               // mpv playpause
    void Rewind();                                  // rewind macro, goes back to beginning or stops playback
    void NewPlayer();                               // creates a new MainWindow
    void OpenFile();                                // open file dialog
    void OpenUrl();                                 // open url dialog
    void FullScreen(bool fs);                       // makes window fullscreen
    void BossMode();                                // run away from the boss
    void JumpToTime();                              // jump to time dialog
    void MediaInfo();                               // media info dialog
    void OpenFileFromClipboard();                   // opens file from cliboard text
    void OpenLastFile();                            // opens last open file (from settings)
    void ShowInFolder();                            // opens explorer to current file's path
    void UpdatePlaylist(QStringList list);          // updates the playlistWidget with the new playlist
    void UpdatePlaylistIndex(int index);            // updates the playlistWidget selection
    void UpdatePlaylistSelectionIndex(int index);   // updates the indexLabel of the playlist
    void PlaylistSelectCurrent();                   // selects the current playlist index
    void PlayIndex(QModelIndex index);              // plays the selected file in the playlist
    void TogglePlaylist();                          // toggle playlist
    void GetPlaylistIndex();                        // selects the file index to play
    void Debug(QString msg);                        // outputs debugging messages
    void OnlineHelp();                              // loads online help
    void CheckForUpdates();                         // checks for program updates
    void AboutQt();                                 // shows qt license information
    void About();                                   // shows baka mplayer about dialog
    void SeekForward();                             // seek +5
    void SeekBack();                                // seek -5
    void AddSubtitleTrack();                        // add a new external subtitle track
    void FitWindow(int percent);                    // fit the window the the specified percent
    void SetAspectRatio(QString spec);              // set the aspect ratio to specified proportions
    void IncreaseFontSize();                        // increase the subtitle font size
    void DecreaseFontSize();                        // decrease the subtitle font size
    void ResetFontSize();                           // reset the subtitle font size
    void DimLights(bool dim);
    void IncreaseVolume();
    void DecreaseVolume();
    void AlwaysOnTop(bool ontop);
    void AlwaysOnTopWhenPlaying(bool ontop);
    void NeverOnTop(bool ontop);
    void ShowInTray(bool show);
    void HidePoppup(bool hide);

private:
    Ui::MainWindow *ui;
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;

    QSettings *settings;

    MpvHandler *mpv;
    PlaylistManager *playlist;

    LightDialog *light;
};

#endif // MAINWINDOW_H