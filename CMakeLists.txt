cmake_minimum_required(VERSION 3.19)
project(SFML_TEST)

set(CMAKE_CXX_STANDARD 14)

add_executable(SFML_TEST main.cpp EventHandler.h StateEnum.h States.h States.cpp SnapshotInterface.h Snapshot.cpp Snapshot.h GUIComponents.h KeyShortcuts.h MouseEvents.h History.h TextInput.cpp TextInput.h Multitext.cpp Multitext.h KeyShortcuts.cpp Letter.h Typing.cpp Typing.h Dropdown.cpp Dropdown.h InputBox.cpp InputBox.h Cursor.cpp Cursor.h ColorCoder.cpp ColorCoder.h colorEnum.h MouseEvents.cpp TextInputStates.h History.cpp HistNode.h Item.cpp Item.h ItemList.cpp ItemList.h DropDownInput.cpp DropDownInput.h MenuBar.cpp MenuBar.h FileTree.cpp FileTree.h FileItem.cpp FileItem.h FileNode.cpp FileNode.h Slider.cpp Slider.h ColorSelector.cpp ColorSelector.h LogoMaker.cpp LogoMaker.h LogoInput.cpp LogoInput.h DropShadow.h DropShadow.cpp Background.cpp Background.h Font.cpp Font.h HSVColorSelect.cpp HSVColorSelect.h Wordle.cpp Wordle.h Grid.cpp Grid.h LetterGrid.cpp LetterGrid.h Score.cpp Score.h)
#Need for SFML
target_link_libraries(SFML_TEST sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)