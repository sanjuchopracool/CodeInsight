#ifndef CODEINSIGHTEDITORWIDGET_H
#define CODEINSIGHTEDITORWIDGET_H

#include <QWidget>
#include <coreplugin/editormanager/ieditor.h>

QT_FORWARD_DECLARE_CLASS(QPushButton)

namespace CodeInsight {
namespace Internal {


class CodeInsightEditorWidget : public QWidget
{
    Q_OBJECT

public:
    CodeInsightEditorWidget(Core::IEditor* editor);
    ~CodeInsightEditorWidget();

private slots:
    void onChanged();

private:
    QPushButton *m_button;
};

#endif // CODEINSIGHTEDITORWIDGET_H

} // namespace Internal
} // namespace codeinsight
