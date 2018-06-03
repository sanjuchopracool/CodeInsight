#include "codeinsighteditorwidget.h"

#include <coreplugin/idocument.h>

#include <QHBoxLayout>
#include <QPushButton>
#include <QSplitter>

namespace CodeInsight {
namespace Internal {

CodeInsightEditorWidget::CodeInsightEditorWidget(Core::IEditor *editor)
{
    m_button = new QPushButton;

    QSplitter *splitter = new QSplitter(this);
    splitter->addWidget(editor->widget());
    splitter->addWidget(m_button);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->setMargin(0);
    layout->addWidget(splitter);
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
