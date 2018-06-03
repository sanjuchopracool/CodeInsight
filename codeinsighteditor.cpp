#include "codeinsighteditor.h"

#include "codeinsighteditorwidget.h"

namespace CodeInsight {
namespace Internal {

CodeInsightEditor::CodeInsightEditor(Core::IEditor *editor)
    : m_editor(editor)
{
    setDuplicateSupported(false);
    m_editorWidget = new CodeInsightEditorWidget(editor);

    // IContext
    setContext(m_editor->context());
    setWidget(m_editorWidget);
    //    setContextHelpId(m_editor->contextHelpId());
}

CodeInsightEditor::~CodeInsightEditor()
{
    delete m_editor;
    delete m_editorWidget;
}

Core::IDocument *CodeInsightEditor::document()
{
    return m_editor->document();
}

QByteArray CodeInsightEditor::saveState() const
{
    return m_editor->saveState();
}

bool CodeInsightEditor::restoreState(const QByteArray &state)
{
    return m_editor->restoreState(state);
}

int CodeInsightEditor::currentLine() const
{
    return m_editor->currentLine();
}

int CodeInsightEditor::currentColumn() const
{
    return m_editor->currentColumn();
}

void CodeInsightEditor::gotoLine(int line, int column, bool centerLine)
{
    m_editor->gotoLine(line, column, centerLine);
}

QWidget *CodeInsightEditor::toolBar()
{
    return m_editor->toolBar();
}

} // namespace Internal
} // namespace codeinsight
