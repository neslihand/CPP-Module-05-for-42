/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndogan <ndogan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:10:31 by ndogan            #+#    #+#             */
/*   Updated: 2025/05/06 14:46:17 by ndogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    // Test 1: Form ve Bureaucrat oluşturma
    std::cout << "----- Test 1: Form ve Bureaucrat oluşturma -----" << std::endl;
    
    // Bureaucrat oluştur
    Bureaucrat b1("Alice", 40);
    Bureaucrat b2("Bob", 50);

    // Form oluştur
    Form f1("Form A", 40, 30); // Alice imzalayabilir
    Form f2("Form B", 60, 20); // Bob imzalayabilir
    
    // Form bilgilerini yazdır
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;

    // Test 2: Form imzalama (başarılı)
    std::cout << "\n----- Test 2: Başarılı imzalama -----" << std::endl;
    b1.signForm(f1); // Alice, Form A'yı imzalamaya çalışacak.
    b2.signForm(f2); // Bob, Form B'yi imzalamaya çalışacak.

    // Test 3: Form imzalama (başarısız)
    std::cout << "\n----- Test 3: Başarısız imzalama -----" << std::endl;
    try {
        b2.signForm(f1); // Bob, Form A'yı imzalayamaz!
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl; // Hata mesajı yazdır.
    }

    // Test 4: Exception handling (çok yüksek derece)
    std::cout << "\n----- Test 4: Çok yüksek derece ile form imzalama -----" << std::endl;
    try {
        Form f3("Form C", -1, 1); 
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl; // Hata mesajı yazdır.
    }

    // Test 5: Exception handling (çok düşük derece)
    std::cout << "\n----- Test 5 : Çok düşük derece ile form imzalama -----" << std::endl;
    try {
        Form f3("Form C", 151, 1); 
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl; // Hata mesajı yazdır.
    }
    // Test 6: Operator overload testi (form bilgilerini yazdırma)
    std::cout << "\n----- Test 6: Form bilgilerini yazdırma -----" << std::endl;
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;

    return 0;
}
