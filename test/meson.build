test_sources = ['selection_sort_test.cpp',
				'bubble_sort_test.cpp']

testexe = executable('testexe', test_sources,
		include_directories : inc, dependencies : [gtest])

test('app test', testexe, args: '--gtest_color=yes')
