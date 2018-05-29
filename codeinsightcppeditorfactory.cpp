#include "codeinsightcppeditorfactory.h"
#include "codeinsightconstants.h"

#include <cppeditor/cppeditorconstants.h>

#include <cpptools/cpptoolsconstants.h>

#include <utils/algorithm.h>
#include <QCoreApplication>

namespace CodeInsight {
namespace Internal {

CodeInsightCppEditorFactory::CodeInsightCppEditorFactory()
{
    setId(Constants::CPPEDITOR_ID);
    setDisplayName(QCoreApplication::translate("OpenWith::Editors", Constants::CPPEDITOR_DISPLAY_NAME));
    addMimeType(CppTools::Constants::C_SOURCE_MIMETYPE);
    addMimeType(CppTools::Constants::CPP_SOURCE_MIMETYPE);

    m_cppEditorFactory = Utils::findOrDefault(IEditorFactory::allEditorFactories(),
                                                   Utils::equal(&IEditorFactory::id,
                                                                Core::Id(CppEditor::Constants::CPPEDITOR_ID)));
}

Core::IEditor *CodeInsightCppEditorFactory::createEditor()
{
    Q_ASSERT(m_cppEditorFactory);
    if ( m_cppEditorFactory )
    {
        return m_cppEditorFactory->createEditor();
    }

    return nullptr;
}

} // namespace Internal
} // namespace codeinsight
