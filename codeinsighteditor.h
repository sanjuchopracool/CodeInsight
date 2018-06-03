#ifndef CODEINSIGHTEDITOR_H
#define CODEINSIGHTEDITOR_H

#include <coreplugin/editormanager/ieditor.h>

namespace CodeInsight {
namespace Internal {

class CodeInsightEditor : public Core::IEditor
{
    Q_OBJECT

public:
    CodeInsightEditor( Core::IEditor *editor );
    ~CodeInsightEditor();

    virtual Core::IDocument *document() override;

    virtual QByteArray saveState() const override;
    virtual bool restoreState(const QByteArray &state);

    virtual int currentLine() const override;
    virtual int currentColumn() const override;
    virtual void gotoLine(int line, int column = 0, bool centerLine = true) override;

    virtual QWidget *toolBar() override;

private:
    Core::IEditor   *m_editor;
};

#endif // CODEINSIGHTEDITOR_H

} // namespace Internal
} // namespace codeinsight
