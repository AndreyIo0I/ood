import {EditorVM} from './viewModel/EditorVM'


//todo синхронизировать курсор с точкой
//todo viewModel -> presenter
window.addEventListener('DOMContentLoaded', initEditor)

function initEditor() {
	new EditorVM()
}
