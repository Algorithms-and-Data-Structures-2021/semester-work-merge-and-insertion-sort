# Здесь вы можете создавать свои исполняемые файлы (executables)
# исполянемый файл = контрольный тест

# Пример создания контрольного теста (исполняемого файла) под названием demo_benchmark.
# Исходный код предоставлен в файле demo_benchmark.cpp текущей директории.
add_executable(merge_sort_benchmark merge_sort_benchmark.cpp)
add_executable(timsort_benchmark timsort_benchmark.cpp)

# Примечание: Не забываем подключить (прилинковать) библиотеку ${PROJECT_NAME} с реализацией структуры данных.
target_link_libraries(merge_sort_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(timsort_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
