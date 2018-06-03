#pragma once

#include <coreplugin/editormanager/ieditorfactory.h>

namespace CodeInsight {
namespace Internal {

class CodeInsightEditorFactory : public Core::IEditorFactory
{
    Q_OBJECT

public:
    CodeInsightEditorFactory();

    Core::IEditor* createEditor();

private:
    Core::IEditorFactory *m_cppEditorFactory = nullptr;
};

} // namespace Internal
} // namespace codeinsight
