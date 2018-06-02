#pragma once

#include <coreplugin/editormanager/ieditorfactory.h>

namespace CodeInsight {
namespace Internal {

class CppEditorFactory : public Core::IEditorFactory
{
    Q_OBJECT

public:
    CppEditorFactory();

    Core::IEditor* createEditor();

private:
    Core::IEditorFactory *m_cppEditorFactory = nullptr;
};

} // namespace Internal
} // namespace codeinsight
