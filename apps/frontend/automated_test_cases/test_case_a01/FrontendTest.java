/*
 * Compile as a .jar package with this command:
 * ?> javac -d ./test_case_a01/classes -classpath "./selenium-server-standalone-3.14.0.jar" ./Helper.java ./test_case_a01/FrontendTest.java; cd ./test_case_a01/classes; jar cfm ../../test_case_a01.jar ../../manifest.mf ./*.class; cd -
 * 
 * Execute with:
 * ?> java -jar test_case_a01.jar
 * 
 * Show details from the JAR file with:
 * ?> jar tvf test_case_a01.jar
 *
 */

import org.openqa.selenium.By;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.chrome.ChromeOptions;
import org.openqa.selenium.Dimension;
import org.openqa.selenium.remote.DesiredCapabilities;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;

import java.util.Date;
import java.io.IOException;
import java.nio.file.*;
import java.text.DateFormat;
import java.text.SimpleDateFormat;


public class FrontendTest
{
    public static void
    main(String[] consoleArguments)
    {
        WebDriver driver = Helper.getChromeWebDriver();

        /* ### */
        /* Resize browser dimension to desktop monitor size. */
        driver.manage().window().setSize(new Dimension(1600, 900));

        Helper.appendTextToLogFile("");
        Helper.appendTextToLogFile("# Test Case A01: \"Are HTML elements like nav, main, footer and debug section available on homepage.\"");
        Helper.appendTextToLogFile("");
        Helper.appendTextToLogFile("Steps for reproduce: ");
        
        /* ### */
        String url = Helper.getBaseUrlForAutomatedTests();

        try
        {
            Helper.appendTextToLogFile("* go to url: " + url);
            driver.get(url);
        }
        catch (Exception exception)
        {
            if (null != driver)
            {
                driver.close();
                driver.quit();
            }

            Helper.appendTextToLogFile("[ERROR] FrontendTest crashed!");
            System.exit(0);
        }

        /* ### */
        String[] textsForXpath = {"//nav", "//main", "//footer", "//div[@id='debug_section']"};

        for( int i = 0; i <= textsForXpath.length - 1; i++)
        {
            Helper.appendTextToLogFile("* check with DOM inspector for the HTML element \"" + textsForXpath[i] + "\"");
            WebElement element = Helper.getWebElementByXpath(driver, textsForXpath[i]);
            
            if (null == element)
            {
                Helper.appendTextToLogFile("[ERROR] FrontendTest #1 stopped: " + textsForXpath[i] + " was not found!");
                System.exit(0);
            }
        }
        
        /* ### */
        Helper.appendTextToLogFile("");

        driver.close();
        driver.quit();
        
        System.exit(0);
    }
}
