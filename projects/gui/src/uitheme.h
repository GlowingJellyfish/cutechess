#ifndef UITHEME_H
#define UITHEME_H

#include <QColor>
#include <QSettings>

struct UITheme {
    QColor m_lightSquare;
    QColor m_darkSquare;
    QColor m_arrow;

    UITheme(): m_lightSquare{0xff, 0xce, 0x9e}, m_darkSquare{0xd1, 0x8b, 0x47}, m_arrow{0, 170, 0} {}
    UITheme(QColor lightSquare, QColor darkSquare, QColor arrow): m_lightSquare{lightSquare}, m_darkSquare{darkSquare}, m_arrow{arrow} {}
};

class UIThemeManager {
public:
    static UIThemeManager& instance() {
        static UIThemeManager tm;
        return tm;
    }

    void registerTheme(const QString name, const UITheme theme) {
        m_themes.insert(name, theme);
    }

    const UITheme currentTheme() const {
        QSettings s;
        QString current_theme = s.value("ui/theme").toString();
        if (!m_themes.contains(current_theme))
            return UITheme{};
        return m_themes[current_theme];
    }
    const QStringList getThemeList() const { return m_themes.keys(); }

private:
    UIThemeManager() = default;
    QMap<QString, UITheme> m_themes;
};

#endif // UITHEME_H