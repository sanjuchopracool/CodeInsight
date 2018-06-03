#include "codeinsighteditorwidget.h"

#include <coreplugin/idocument.h>

#include <QHBoxLayout>
#include <QPushButton>

namespace CodeInsight {
namespace Internal {

CodeInsightEditorWidget::CodeInsightEditorWidget(Core::IEditor *editor)
{
    m_button = new QPushButton;

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(editor->widget());
    layout->addWidget(m_button);
    setLayout(layout);

    connect(editor->document(),
            SIGNAL(changed()),
            SLOT(onChanged()));
}

CodeInsightEditorWidget::~CodeInsightEditorWidget()
{
}

void CodeInsightEditorWidget::onChanged()
{
    static int count = 0;
    m_button->setText( "Clicked" + QString::number(count++));
}

} // namespace Internal
} // namespace codeinsight
