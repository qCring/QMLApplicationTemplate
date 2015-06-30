# ******************************************************************************************************************************************************************
function(PrintList _title _list)
	message(STATUS "> " ${_title} ":")
	foreach(_file ${_list})
		message(STATUS "  " ${_file})
	endforeach()
	message(STATUS "")
endfunction()

# AddSourceFolder - AddSourceFolder("src/group" "group" list_src)
# rel_path 		= relative path of target src group
# group_name 	= name of target src group
# list_src 		= list of target sources from parent scope
# ******************************************************************************************************************************************************************
function(AddSrc rel_path group_name list_src)
	message(STATUS "> Add src dir: " ${ROOT_DIR}/${rel_path} " =>  " ${group_name})
	message(STATUS "")
	include_directories(${rel_path})
	file(GLOB list_globbed "${rel_path}/*.h" "${rel_path}/*.cpp")
	set(list_return ${list_globbed} ${${list_src}})
	set(${list_src} ${list_return} PARENT_SCOPE)
	source_group(${group_name} FILES ${list_globbed})
endfunction()

# AddResFolder group
# rel_path 		= relative path of target res group
# group_name 	= name of target res group
# list_res 		= list of target resources from parent scope
# ******************************************************************************************************************************************************************
function(AddRes rel_path group_name list_res)
	message(STATUS "> Add res dir: " ${ROOT_DIR}/${rel_path} " =>  " ${group_name})
	message(STATUS "")
	include_directories(${ROOT_DIR}/res/${rel_path})
	file(GLOB list_globbed "${rel_path}/*.qml" "${rel_path}/*.png" "${rel_path}/*.ttf" "${rel_path}/*.js" "${rel_path}/*.json")
	source_group(${group_name} FILES ${list_globbed})
	set(list_return ${list_globbed} ${${list_res}})
	set(${list_res} ${list_return} PARENT_SCOPE)
endfunction()
