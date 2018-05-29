#pragma once

#include <coreplugin/editormanager/ieditorfactory.h>

namespace CodeInsight {
namespace Internal {

class CodeInsightCppEditorFactory : public Core::IEditorFactory
{
    Q_OBJECT

public:
    CodeInsightCppEditorFactory();

    Core::IEditor* createEditor();

private:
    Core::IEditorFactory *m_cppEditorFactory = nullptr;
};

} // namespace Internal
} // namespace codeinsight
